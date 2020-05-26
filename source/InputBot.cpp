#include "InputBot.hpp"

InputBot::InputBot() {}

void InputBot::changeMode(MODE mode)
{
    if (this->mode != MODE::KEYBOARD && mode == MODE::KEYBOARD)
    {
        _buffer->type = INPUT_KEYBOARD;
        _buffer->ki.wScan = 0;
        _buffer->ki.time = 0;
        _buffer->ki.dwExtraInfo = 0;
    }
    else if (this->mode != MODE::MOUSE && mode == MODE::MOUSE) {
        _buffer->type = INPUT_MOUSE;
    }

    this->mode = mode;
}

void InputBot::KeyUp(char key)
{
    _buffer->ki.wVk = key;
    _buffer->ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, _buffer, sizeof(INPUT));
}

void InputBot::KeyDown(char key)
{
    _buffer->ki.wVk = key;
    _buffer->ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
    SendInput(1, _buffer, sizeof(INPUT));
}

void InputBot::KeyClick(char key)
{
    KeyDown(key);
    Sleep(10);
    KeyUp(key);
}

void InputBot::MouseMove(double x, double y)
{
    double fScreenWidth = GetSystemMetrics(SM_CXSCREEN) - 1;
    double fScreenHeight = GetSystemMetrics(SM_CYSCREEN) - 1;
    double fx = x * (65535.0f / fScreenWidth);
    double fy = y * (65535.0f / fScreenHeight);

    _buffer->type = INPUT_MOUSE;
    _buffer->mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
    _buffer->mi.dx = fx;
    _buffer->mi.dy = fy;
    SendInput(1, _buffer, sizeof(INPUT));
}

void InputBot::MouseLeftClick()
{
    // left down 
    _buffer->mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, _buffer, sizeof(INPUT));

    // left up
    ZeroMemory(_buffer, sizeof(INPUT));
    _buffer->type = INPUT_MOUSE;
    _buffer->mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, _buffer, sizeof(INPUT));

}

void InputBot::MouseRightClick()
{
    // right down  
    _buffer->mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    SendInput(1, _buffer, sizeof(INPUT));

    // right up
    ZeroMemory(_buffer, sizeof(INPUT));
    _buffer->type = INPUT_MOUSE;
    _buffer->mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    SendInput(1, _buffer, sizeof(INPUT));
}


void InputBot::MouseLeftClickDown()
{
    _buffer->mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, _buffer, sizeof(INPUT));

}

void InputBot::MouseLeftClickUp()
{
    ZeroMemory(_buffer, sizeof(INPUT));
    _buffer->type = INPUT_MOUSE;
    _buffer->mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, _buffer, sizeof(INPUT));
}

void InputBot::MouseRightClickDown()
{
    _buffer->mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    SendInput(1, _buffer, sizeof(INPUT));
}

void InputBot::MouseRightClickUp()
{
    ZeroMemory(_buffer, sizeof(INPUT));
    _buffer->type = INPUT_MOUSE;
    _buffer->mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    SendInput(1, _buffer, sizeof(INPUT));
}



