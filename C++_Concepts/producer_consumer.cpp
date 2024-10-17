/*
    Producer & Consumer





*/


#include<bits/stdc++.h>
using namespace std;

namespace own
{
    // std::queue<int> qu;   

    // class Producer
    // {
    //    public:

    //    private: 
    // };

    // class Consumer
    // {
    //     public:
    //     private:
    // };
}

std::mutex mu;
std::condition_variable cv;
bool OddSignal = false;
bool EvenSignal = true; 

void printOdd()
{
    for(int i = 1 ; i < 10; i = i + 2)
    { 
        std::unique_lock<std::mutex> lock(mu);
        cv.wait(lock, [] { return OddSignal == true ;});        
        cout << "Odd Number = " << i << endl;             
        EvenSignal = true;
        OddSignal = false;
        cv.notify_all();
    }
}

void printEven()
{
    for(int i = 2 ; i <= 10; i = i + 2)
    {
        std::unique_lock<std::mutex> lock(mu);
        cv.wait(lock, [] { return EvenSignal == true ;});     
        cout << "Even Number = " << i << endl;             
        OddSignal = true;
        EvenSignal = false;
        cv.notify_all();
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