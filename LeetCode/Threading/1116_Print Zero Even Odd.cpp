#include<bits/stdc++.h>
#include<thread>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    int setZero = 0;
    bool oddVar = true;
    std::mutex m1;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i = 0 ; i < n ; ++i)
        {
            unique_lock<mutex> lock(m1);
            cv.wait(lock,[this](){return setZero == 0;});
            printNumber(0);
            setZero = 1;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
       for(int i = 2 ; i <= n ; i = i + 2)
       {
            unique_lock<mutex> lock(m1);
            cv.wait(lock,[this](){return setZero == 1 && oddVar == false;});
            printNumber(i);
            setZero = 0;
            oddVar = true;
            cv.notify_all();
       } 
    }

    void odd(function<void(int)> printNumber) {
       for(int i = 1 ; i <= n ; i = i + 2)
       {
            unique_lock<mutex> lock(m1);
            cv.wait(lock,[this](){return setZero == 1 && oddVar == true;});
            printNumber(i);
            setZero = 0;
            oddVar = false;
            cv.notify_all();
       } 
    }
};