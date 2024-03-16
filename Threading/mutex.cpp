#include<iostream>
#include<thread>
#include<mutex>

using namespace std;
mutex m;
int myAmount = 0;

void addMoney()
{
    m.lock();
    myAmount++;
    m.unlock();
}

int main()
{
    thread t1(addMoney);
    thread t2(addMoney);

    t1.join();
    t2.join();

    cout << myAmount << endl;
    return 0;
}