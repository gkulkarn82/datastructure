//Topic : Future and Promise in threading

/*
    Notes :
1. std:promise 
        Used to set values or exception
2. std:future
       a. Used to get values from promise
       b. Ask promise if the value is available
       c. wait for the promise
*/

#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include<future>

using namespace std;
using namespace std::chrono;
typedef long int ull;

void findOdd(std::promise<ull>&& OddSumPromise, ull start, ull end)
{
    ull oddSum = 0;
    for(ull i = start ; i < end; i++)
    {
        if(i & 1)
            oddSum += i;
    }
    OddSumPromise.set_value(oddSum);
}

int main()
{
    ull start = 0, end = 1900000000;

    std::promise<ull> oddSum ;
    std::future<ull> oddFuture = oddSum.get_future();

    cout << "Thread Created !! " << endl;
    std::thread t1(findOdd, std::move(oddSum), start, end);

    cout<< "Waiting for the result" << endl;
    cout << "oddSum :  " << oddFuture.get() << endl;
    cout << "completed " << endl;;
    t1.join();

    return 0; 
}