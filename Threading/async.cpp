//Tpoic std:async

/*
    Notes:
    1. It runs a function asynchronusly ( potentially in a new thread) and returns std:future that will hold 
        the results
    2. There are three launch policies for creating task
            1. std::launch::async
            2. std::launch::deffered
            3. std::launch::async | std::launch::deffered

    How It Works
    1. It automatically creates thread (Or picks from the internal thread pool) and a promise object for us.
    2. Then passes the std::promise object to thread functions and returns the associated furture object.
    3. When our passed argument function exits then it's value will be set in this promise object
        so eventually return value will be available in std::future object

    We can send functor and lambda functions as callback to std:async  it will work the same.
*/

#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include<future>

using namespace std;
using namespace std::chrono;

typedef long int ull;

ull findOdd(ull start, ull end)
{
    ull oddSum = 0;
    for(ull i = start ; i < end; i++)
    {
        if(i & 1)
            oddSum += i;
    }   
    return oddSum ;
}

int main()
{
    ull start = 0, end = 1900000000;

    std::future<ull> oddSum = std::async(std::launch::deferred, findOdd, start, end);

    cout<< "Waiting for the result" << endl;
    cout << "oddSum :  " << oddSum.get() << endl;
    cout << "completed " << endl;;
  
    return 0; 
}