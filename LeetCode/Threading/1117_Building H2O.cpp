#include<bits/stdc++.h>
#include<thread>
using namespace std;

class H2O {  
    bool releaseMe = true;
    int countHydro = 0;
    std::mutex m1;
    condition_variable cv;
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(m1);
        cv.wait(lock,[this]() {return releaseMe == true;});      
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++countHydro;       
        if(countHydro == 2)
            releaseMe = false;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(m1);
        cv.wait(lock, [this](){ return releaseMe == false;});
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        releaseMe = true;
        countHydro = 0;
        cv.notify_all();
    }
};