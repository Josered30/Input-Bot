#include <iostream>
#include <conio.h>
#include <chrono>
#include "InputBot.hpp"
#include "InputBotCommands.hpp"

using namespace std;


//Unicode UTF-16 -> U+25CF -> U000025 -> 000025 (8 Numbers)

int main(int argsc, char *argv[])
{
    
    InputBot *keyboardBot = new InputBot();
    InputBot *mouseBot = new InputBot();
   
    mouseBot->changeMode(MODE::MOUSE);
    keyboardBot->changeMode(MODE::KEYBOARD);

    char option;
    
    //char flag = 'A';
    bool mouse_flag[] = { true, true };
    bool keyboard_flag = true;

    cout << "===============================================" <<endl;
    cout << "||           Welcome to the input-bot         ||" <<endl;
    cout << "===============================================" <<endl;
    cout << "\U000025CF Press G to hold/release left click "<<endl;
    cout << "\U000025CF Press X to exit "<<endl;

    

    //chrono::system_clock::time_point time_aux = chrono::system_clock::now();

    while (true)
    {
        leftMousePress('g',mouse_flag[0],mouseBot);
        keyHoldDown('h','W',keyboardBot, keyboard_flag);

        if(GetKeyState('x') & 0x8000 || GetKeyState(toupper('X')) & 0x8000)
            break;

        std::this_thread::sleep_for (std::chrono::milliseconds(150));


        /*if (chrono::system_clock::now() >= time_aux + chrono::seconds(4))
        {
            for (int i = 0; i < 25; ++i)
            {
                bot->KeyDown(flag);
                Sleep(100);
            }

            bot->KeyUp(flag);

            //future<void> future_1 = async(std::launch::async, &InputBot::KeyUp,bot,flag);
            //if (future_1.wait_for(chrono::seconds(2)) == std::future_status::ready) {
            //future_1.get();

            if (flag == 'A')
                flag = 'D';
            else
                flag = 'A';

            //}
            time_aux = chrono::system_clock::now();
        }

        bot->KeyClick('G');
        Sleep(100);*/
    }


    return 0;
}