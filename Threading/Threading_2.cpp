#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

std::mutex mu;
std::condition_variable cd;
int count = 1;

void printOdd()
{
    for(; count < 100;)
    {
        std::unique_lock<std::mutex> locker(mu);
        cd.wait(locker,[]() { return (count % 2 == 1); });
        std::cout << "From Odd:   " << count << std::endl;
        count++;
        locker.unlock();
        cd.notify_all();
    }
}

void printEven()
{
    for(; count < 100;)
    {
        std::unique_lock<std::mutex> locker(mu);
        cd.wait(locker, []() { return (count % 2 == 0); });
        std::cout << "From even:   " << count << std::endl;
        count++;
        locker.unlock();
        cd.notify_all();
    }
}

int main()
{
    std::thread t1(printOdd);
    std::thread t2(printEven);

    t1.join();
    t2.join();

    return 0;
}