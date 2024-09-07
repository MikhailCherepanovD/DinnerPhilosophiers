#pragma once
#include "libs.h"
#include "Fork.h"
class Philosopher {
    int status; //1 - беседует, 2 - хочет есть, 3 - ест
    bool left; // 0 - нет вилки, 1 - есть вилка
    bool right;
    int index;
    Fork& leftFork;
    Fork& rightFork;
    mutex mtx;
    void atomicPrintAction(string&& str){
        lock_guard<mutex> guard(mtx);
        cout<<"Philosopher №"<<index<<" "<< move(str) <<endl;
    }
public:
/*    Philosopher(){
        index=0;
        left = 0;
    }*/
    Philosopher(int index, Fork& leftFork,Fork& rightFork):
    index(index),leftFork(leftFork),rightFork(rightFork){

    };
    void speak(){
        atomicPrintAction("started speak");
        this_thread::sleep_for(chrono::milliseconds(1000));
        atomicPrintAction("finished speak");
    }
    void wait(){

    }
    void eat(){
        atomicPrintAction("started eat");
        this_thread::sleep_for(chrono::milliseconds(1000));
        atomicPrintAction("finished eat");
    }
    void try_eat(){
        if(!leftFork.lockIfIsFree()){
            atomicPrintAction("left is buzy");
            return;
        }
        if(!rightFork.lockIfIsFree()){
            atomicPrintAction("right is buzy");
            leftFork.unlock();
            return;
        }
        eat();
        leftFork.unlock();
        rightFork.unlock();

    }
    void run(){
        while(true){
            speak();
            try_eat();
        }
    }
};


