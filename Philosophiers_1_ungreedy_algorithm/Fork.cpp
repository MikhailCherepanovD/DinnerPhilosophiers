#include "Fork.h"
Fork::Fork():isFree(1){};

bool Fork::lockIfIsFree(){
    if(!isFree){
        return 0;
    }
    isFree = 0;
    return 1;
}

void Fork::unlock(){
    isFree = 1;
}