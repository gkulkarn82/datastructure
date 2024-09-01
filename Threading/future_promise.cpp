//Topic : Future and Promise in threading

/* 
Notes :

The class template std::promise provides a facility to store a value or an exception that is later acquired 
asynchronously via a std::future object created by the std::promise object. 

Note that the std::promise object is meant to be used only once.

Each promise is associated with a shared state, which contains some state information and a result which may be not yet 
evaluated, evaluated to a value (possibly void) or evaluated to an exception. A promise may do three things with the 
shared state:

make ready: 
    the promise stores the result or the exception in the shared state. Marks the state ready and unblocks any thread 
    waiting on a future associated with the shared state.

release: 
    the promise gives up its reference to the shared state. If this was the last such reference, the shared state is 
    destroyed. Unless this was a shared state created by std::async which is not yet ready, this operation does not 
    block.

abandon: 
    the promise stores the exception of type std::future_error with error code std::future_errc::broken_promise, 
    makes the shared state ready, and then releases it.

The promise is the "push" end of the promise-future communication channel: the operation that stores a value in the 
shared state synchronizes-with (as defined in std::memory_order) the successful return from any function that is 
waiting on the shared state (such as std::future::get). Concurrent access to the same shared state may conflict 
otherwise: 

for example multiple callers of std::shared_future::get must either all be read-only or provide external 
synchronization.

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