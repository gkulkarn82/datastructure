/*
The recursive_mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads.

recursive_mutex offers exclusive, recursive ownership semantics:

A calling thread owns a recursive_mutex for a period of time that starts when it successfully calls either lock or try_lock. 
During this period, the thread may make additional calls to lock or try_lock. The period of ownership ends when the thread makes a matching number 
of calls to unlock.
When a thread owns a recursive_mutex, all other threads will block (for calls to lock) or receive a false return value (for try_lock) 
if they attempt to claim ownership of the recursive_mutex.
The maximum number of times that a recursive_mutex may be locked is unspecified, but after that number is reached, calls to lock will throw 
std::system_error and calls to try_lock will return false.
The behavior of a program is undefined if a recursive_mutex is destroyed while still owned by some thread. 
The recursive_mutex class satisfies all requirements of Mutex and StandardLayoutType.


*/
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::recursive_mutex ml;
int buffer = 0;

void recusion(char c, int loopFor)
{
    if(loopFor < 0)
        return;
    ml.lock();
    cout << c << " " << buffer++ << endl;
    recusion(c, --loopFor);
    ml.unlock();    
    cout << "Unlock by thread " << c << endl;
}

int main()
{
    thread t1(recusion, '0', 10);
    thread t2(recusion, '1', 10);

    t1.join();
    t2.join();

    return 0;
}