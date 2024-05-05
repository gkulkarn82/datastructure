#include<bits/stdc++.h>
#include<thread>
using namespace std;

class FizzBuzz {
private:
    int n;
    int start = 1;
    std::mutex m1;
    condition_variable cv;
public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(start <= n)
        {
            unique_lock<mutex> lock(m1);
            cv.wait(lock,[this](){return (start > n) || ((start % 3 == 0) && (start % 5 != 0));});
            if(start > n)
                break;
            printFizz();
            ++start;
            cout << "Start = " << start << " n = " << n << endl;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(start <= n)
        {
            unique_lock<mutex> lock(m1);
            cv.wait(lock,[this](){return (start > n) || ((start % 3 != 0) && (start % 5 == 0));});
            if(start > n)
                break;
            printBuzz();
            ++start;
            cout << "Start = " << start << " n = " << n << endl;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(start <= n)
        {
            unique_lock<mutex> lock(m1);
            cv.wait(lock,[this](){return (start > n) || ((start % 3 == 0) && (start % 5 == 0));});
            if(start > n)
                break;
            printFizzBuzz();
            ++start;
            cout << "Start = " << start << " n = " << n << endl;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(start <= n)
        {
            unique_lock<mutex> lock(m1);
            cv.wait(lock,[this](){return (start > n) || ((start % 3 != 0) && (start % 5 != 0));});
            if(start > n)
                break;
            printNumber(start);
            ++start;
            cout << "Start = " << start << " n = " << n << endl;
            cv.notify_all();
        }
    }
};