#pragma once
#include "libs.h"
#include "Fork.h"
class Philosopher {
    static int GENERAL_AMOUNT_EAT;
    static mutex OUTPUT_PHILOSOPHER_MUTEX;
    int index;
    int amountTimesEat;
    int& generalAMOUNT;
    Fork& leftFork;
    Fork& rightFork;
    mutex& mtx;
    void atomicPrintAction(string&& str);
public:
    Philosopher(int index, Fork& leftFork,Fork& rightFork);
    void speak();
    void eat();
    void try_eat();
    void run();
    void printAmountTimesEat();
};


