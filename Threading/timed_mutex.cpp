/*
    The timed_mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads.

    In a manner similar to mutex, timed_mutex offers exclusive, non-recursive ownership semantics. 
    In addition, timed_mutex provides the ability to attempt to claim ownership of a timed_mutex with a timeout via the 
    member functions try_lock_for() and try_lock_until().

    The timed_mutex class satisfies all requirements of TimedMutex and StandardLayoutType.


    Locking

    lock :  locks the mutex, blocks if the mutex is not available (public member function)
    try_lock : tries to lock the mutex, returns if the mutex is not available (public member function)
    try_lock_for : tries to lock the mutex, returns if the mutex has been unavailable for the specified timeout duration (public member function)
    try_lock_until: tries to lock the mutex, returns if the mutex has been unavailable until specified time point has been reached (public member function)
    unlock : unlocks the mutex (public member function)
*/

#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

int myAmount = 0;
std::timed_mutex m; 

void increment(int i)
{
    if(m.try_lock_for(std::chrono::seconds(2)))
    {
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Thread " << i << " Entered " << endl;
        m.unlock();
    }
    else
        cout << "Thread " << i << " Couldn't Entered " << endl;
}

void increment_caseII(int i)
{
    auto now = std::chrono::steady_clock::now();
    if(m.try_lock_until(now + std::chrono::seconds(1)))
    {
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "Thread " << i << " Entered " << endl;
        m.unlock();
    }
    else
        cout << "Thread " << i << " Couldn't Entered " << endl;
}

int main()
{
    thread t1(increment, 1);
    thread t2(increment, 2);

    t1.join();
    t2.join();

    cout << myAmount << endl;

    thread t3(increment_caseII, 3);
    thread t4(increment_caseII, 4);

    t3.join();
    t4.join();

    cout << myAmount << endl;
    return 0;
}