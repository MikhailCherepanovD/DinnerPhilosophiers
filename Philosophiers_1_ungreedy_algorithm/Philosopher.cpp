#include "Philosopher.h"
int Philosopher::GENERAL_AMOUNT_EAT=0;
mutex Philosopher::OUTPUT_PHILOSOPHER_MUTEX;

Philosopher::Philosopher(int index, Fork& leftFork, Fork& rightFork):
    index(index),leftFork(leftFork),rightFork(rightFork),amountTimesEat(0),mtx(OUTPUT_PHILOSOPHER_MUTEX),generalAMOUNT(GENERAL_AMOUNT_EAT){};

void Philosopher::speak(){
    atomicPrintAction("started speak");
    this_thread::sleep_for(chrono::milliseconds(2));
    atomicPrintAction("finished speak");
}

void Philosopher::eat(){
    atomicPrintAction("started eat");
    this_thread::sleep_for(chrono::milliseconds(3));
    amountTimesEat++;
    generalAMOUNT++;
    atomicPrintAction("finished eat");
}

void Philosopher::try_eat(){
    if(!leftFork.lockIfIsFree()){
        atomicPrintAction("left is busy");
        return;
    }
    if(!rightFork.lockIfIsFree()){
        atomicPrintAction("right is busy");
        leftFork.unlock();
        return;
    }
    eat();
    leftFork.unlock();
    rightFork.unlock();
}

void Philosopher::run(){
    while(generalAMOUNT<100){
        speak();
        try_eat();
    }
}

void Philosopher::printAmountTimesEat(){
    atomicPrintAction(to_string(amountTimesEat));
}

void Philosopher::atomicPrintAction(string&& str){
    lock_guard<mutex> guard(mtx);
    cout<<"Philosopher №"<<index<<" "<< move(str) <<endl;
}