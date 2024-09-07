#include "libs.h"
#include "Fork.h"
#include "Philosopher.h"
const int N = 5;
int main() {
    shared_ptr<Fork> forks[N];
    shared_ptr<Philosopher> philosophers[N];
    unique_ptr<thread> threads[N];
    for(int i=0;i<N;i++){
        forks[i]= make_shared<Fork>();
    }
    for(int i=0;i<N;i++){
        if(i==0) {
            philosophers[i] = make_shared<Philosopher>(i, *forks[N - 1], *forks[i]);
            continue;
        }
        philosophers[i] = make_shared<Philosopher>(i, *forks[i-1], *forks[i]);
    }
    for(int i=0;i<N;i++){
        threads[i] = make_unique<thread>(bind(&Philosopher::run,philosophers[i]));
    }
    for(int i=0;i<N;i++){
        threads[i]->join();
    }
    for(int i=0;i<N;i++){
        philosophers[i]->printAmountTimesEat();
    }
    return 0;
}
