#ifndef __INPUT_BOT_COMMANDS__
#define __INPUT_BOT_COMMANDS__
#include "InputBot.hpp"
#include <thread>
#include<mutex>

void leftMousePress(char key, bool &flag, InputBot *&mouseBot);
void keyHoldDown(char key, char holdKey, InputBot *&keyBot, bool &flag);


#endif