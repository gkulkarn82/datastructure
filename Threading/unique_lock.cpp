/*
Unique lock
A unique lock is an object that manages a mutex object with unique ownership in both states: locked and unlocked.

On construction (or by move-assigning to it), the object acquires a mutex object, for whose locking and unlocking operations becomes responsible.

The object supports both states: locked and unlocked.

This class guarantees an unlocked status on destruction (even if not called explicitly). 
Therefore it is especially useful as an object with automatic duration, as it guarantees the mutex object is properly unlocked in case an 
exception is thrown.

Note though, that the unique_lock object does not manage the lifetime of the mutex object in any way: the duration of the mutex object shall 
extend at least until the destruction of the unique_lock that manages it.


*/

#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

std::mutex ml;
int buffer = 0;

//Example 1
// void task(const char* threadNumber, int loopFor)
// {
//     std::unique_lock<mutex> lock(ml);
//     for(int i =0 ; i < loopFor; i++)
//     {
//         buffer++;
//         cout << threadNumber << buffer << endl;
//     }
// }

void task(const char* threadNumber, int loopFor)
{
    std::unique_lock<mutex> lock(ml, std::defer_lock);
    lock.lock();
    for(int i =0 ; i < loopFor; i++)
    {
        buffer++;
        cout << threadNumber << buffer << endl;
    }
}

int main()
{
    thread t1(task, "T1 ", 10);
    thread t2(task, "T2 ", 10);

    t1.join();
    t2.join();

    return 0;
}


