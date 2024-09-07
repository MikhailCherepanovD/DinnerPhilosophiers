#pragma once
#include "libs.h"
class Fork {
    bool isFree; // 1 - свободна, 0 - взяли
    mutex mtx;
public:
    Fork();
    bool lockIfIsFree();
    void unlock();
};
