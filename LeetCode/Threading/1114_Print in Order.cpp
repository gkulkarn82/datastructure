#include<bits/stdc++.h>
#include<thread>
using namespace std;

class Foo {
    int i = 0;
    mutex m1;
    condition_variable cv;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(m1);
        cv.wait(lock,[this](){return i == 0; });
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        i = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m1);
        cv.wait(lock,[this](){return i == 1; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        i = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m1);
        cv.wait(lock,[this](){return i == 2; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        i = 0;
        cv.notify_all();
    }
};