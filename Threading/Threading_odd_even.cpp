#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

#define MAX 100
static int i = 0;
std::mutex mu;
std::condition_variable cond;


void even()
{
    while(i < MAX)
    {
        std::unique_lock<mutex> locker(mu);
        cond.wait(locker,[](){return (i % 2 == 0);});       
        cout << "Even number is :" << i<< endl;        
        i++;
        locker.unlock();
        cond.notify_all();
    }
}

void odd()
{
    while(i < MAX)
    {
        std::unique_lock<mutex> locker(mu);
        cond.wait(locker, [](){return (i % 2 == 1); });
        cout << "Odd number is :" << i << endl;
        i++;
        locker.unlock();
        cond.notify_all();
   }
}


int main()
{
    thread t1(even);
    thread t2(odd);

    t1.join();
    t2.join();

    return 0;
}