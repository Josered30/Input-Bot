#include "InputBotCommands.hpp"

//GetAsyncKeyState -> HoldKey
//GetKeyState -> One input 
std::mutex _mutex;

//std::lock_guard<std::mutex> guard(_mutex); only in scope


void leftMousePress(char key, bool &flag, InputBot *&mouseBot){   
    if((GetKeyState(key) & 0x8000) || (GetKeyState(toupper(key)) & 0x8000) && flag){
        mouseBot->MouseLeftClickDown();
        flag = false;   
    }  
    else if(GetKeyState(key) ==0 && GetKeyState(toupper(key)) == 0 && !flag){
        mouseBot->MouseLeftClickUp();     
        flag = true;
    }
}


void keyHoldDown(char key, char holdKey, InputBot *&keyBot, bool &flag){

    if(GetKeyState(key) & 0x8000 || GetKeyState(toupper(key)) & 0x8000){

        if(flag){      
            std::thread hold([](char holdKey, InputBot *&keyBot ,bool &flag)->void{ 
                flag = false;
    
                while(!flag){  
                    _mutex.lock();             
                    printf("continue\n"); 
                    _mutex.unlock();
                    keyBot->KeyDown(holdKey); 
                    std::this_thread::sleep_for (std::chrono::milliseconds(150));       
                }  

                }, holdKey,std::ref(keyBot) , std::ref(flag));
            hold.detach();
        } else{

            flag = true;
            _mutex.lock();             
            printf("stop\n"); 
            _mutex.unlock();

            keyBot->KeyClick(holdKey);         
        }       

    }  
}
