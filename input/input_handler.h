#pragma once

class IInputHandler {
public:
    virtual void handleTouch(int, int, bool, bool) = 0;
    virtual void handleMove(int, int) = 0;

};