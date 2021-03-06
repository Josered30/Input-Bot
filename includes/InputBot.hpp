#ifndef __INPUTBOT_HPP__
#define __INPUTBOT_HPP__
#include <windows.h>


enum MODE
{
    MOUSE,
    KEYBOARD
};


class InputBot
{
private:
    INPUT _buffer[1];
    MODE mode;

public:
    InputBot();
    void changeMode(MODE mode);

    void KeyUp(char key);
    void KeyDown(char key);
    void KeyClick(char key);

    void MouseMove(double x, double y);
    void MouseLeftClick();
    void MouseRightClick();

    void MouseLeftClickDown();
    void MouseLeftClickUp();

    void MouseRightClickDown();
    void MouseRightClickUp();

    void cleanBuffer();
};



#endif