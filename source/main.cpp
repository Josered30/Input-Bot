#include "mingw.future.h"
#include "mingw.thread.h"
#include <iostream>
#include <conio.h>
#include <chrono>
#include "InputBot.hpp"

using namespace std;


int main()
{

    InputBot* bot = new InputBot();
    char option;
    char flag = 'A';
    chrono::system_clock::time_point time_aux = chrono::system_clock::now();

    bot->changeMode(MODE::KEYBOARD);

    while (true)
    {
        if (_kbhit())
        {
            option = _getch();
            option = toupper(option);

            if (option == 'X')
                break;

            /*if(option == 'A')
                bot->MouseLeftClick();

              if(option == 'D')
                bot->MouseRightClick();*/
        }
    
        if (chrono::system_clock::now() >= time_aux + chrono::seconds(4)){

            for(int i =0; i<25; ++i){
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
        Sleep(100);

    }

    return 0;
}