#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

long long bankBalance = 0;

void addMoney(long long val)
{
    bankBalance += val;
}

int main()
{
    thread t1(addMoney, 100);
    thread t2(addMoney, 200);

    t1.join();
    t2.join();
    cout << "Final BankBalance: " << bankBalance << endl;
    return 0;
}