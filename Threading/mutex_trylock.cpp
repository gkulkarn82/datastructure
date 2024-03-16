#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int counter = 0;
mutex m;

void increaseTheCounterFor100000Time()
{
    for(int i = 0; i < 100000; ++i)
    {
        // This is a non blocking call
        if(m.try_lock())
        {
            ++counter;
            m.unlock();
        }
    }
}

int main()
{
    thread t1(increaseTheCounterFor100000Time);
    thread t2(increaseTheCounterFor100000Time);

    t1.join();
    t2.join();

    cout << "counter could increase up tp : " << counter << endl;
}