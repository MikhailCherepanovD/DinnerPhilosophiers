#pragma once
#include "libs.h"
class Fork {
    bool isFree; // 1 - свободна, 0 - взяли
    mutex mtx;
public:
    Fork():isFree(1){};
    bool getIsFree(){
        return isFree;
    }
    bool lockIfIsFree(){
        if(!isFree){
            return 0;
        }
        isFree = 0;
        return 1;
    }
    void lock(){
        isFree = 0;
    }
    void unlock(){
        isFree = 1;
    }
};
