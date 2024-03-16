#include<iostream>
#include<mutex>
using namespace std;

std::recursive_mutex ml;

int main()
{
    for(int i =0 ; i < 5; i++)
    {
        ml.lock();
        std::cout<< "locked " << i << std::endl;
    }

    for(int i =0 ; i < 5; i++)
    {
        ml.unlock();
        std::cout<< "unlocked " << i << std::endl;
    }

    return 0;
}