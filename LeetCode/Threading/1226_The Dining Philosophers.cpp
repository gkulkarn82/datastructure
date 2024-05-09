#include<bits/stdc++.h>
#include<thread>
using namespace std;

class DiningPhilosophers {    
    std::binary_semaphore forks[5] = {
                                        std::binary_semaphore(1),
                                        std::binary_semaphore(1),
                                        std::binary_semaphore(1),
                                        std::binary_semaphore(1),
                                        std::binary_semaphore(1)
                                    };
    int size = 5;
    std::mutex mu;  
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        lock_guard<std::mutex> lock(mu);
        int left = philosopher;
        int right = (philosopher == 0) ? size - 1 : philosopher - 1;
      
        forks[left].acquire();
        forks[right].acquire();
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();      
        forks[left].release();
        forks[right].release();
    }
};