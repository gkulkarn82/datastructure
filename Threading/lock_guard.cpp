/*
The class lock_guard is a mutex wrapper that provides a convenient RAII-style mechanism for owning a mutex for the duration of a scoped block.

When a lock_guard object is created, it attempts to take ownership of the mutex it is given. When control leaves the scope in which 
the lock_guard object was created, the lock_guard is destructed and the mutex is released.

The lock_guard class is non-copyable.
*/
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex ml;
int buffer = 0;

void task(const char* threadNumber, int loopFor)
{
    std::lock_guard<mutex> lock(ml);
    //ml.lock();
    for(int i = 0 ; i < loopFor; i++)
    {
        buffer++;
        cout << threadNumber << buffer << endl;
    }
    //ml.unlock();
}

int main()
{
    thread t1(task, "T0 ", 10);
    thread t2(task, "T1 ", 10);

    t1.join();
    t2.join();

    return 0;
}