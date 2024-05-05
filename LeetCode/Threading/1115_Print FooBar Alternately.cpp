#include<bits/stdc++.h>
#include<thread>
using namespace std;

class FooBar {
private:
    int n;
    std::mutex m1;
    condition_variable cv;
    bool isTrue = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m1);
            cv.wait(lock, [this](){return isTrue ;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            isTrue = !isTrue;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m1);
            cv.wait(lock, [this](){return !isTrue ;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            isTrue = !isTrue;
            cv.notify_all();
        }
    }
};