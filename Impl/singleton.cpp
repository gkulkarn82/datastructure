#include<bits/stdc++.h>
using namespace std;

class Singleton
{
    //static instance variable of class 
    static Singleton* _instance ;
    static std::mutex mutex;

    //private constructor
    Singleton(){}

public:
    //using delete operator to remove copy constructor 
    //which lead to stop people from creating copy of class
    Singleton(const Singleton& obj) = delete;
    Singleton& operator =(const Singleton&) = delete;

    static Singleton* getInstance()
    {
        if(_instance == NULL)
        {
            std::lock_guard<std::mutex> lock(mutex);            
            if(_instance == NULL)            
                _instance = new Singleton();
        }
        return _instance;
    }
};

/*
    This declaration is needed as the static class member is stored 
    speratly rather than as part of class object
*/
Singleton* Singleton:: _instance = NULL;
std::mutex Singleton::mutex;

int main()
{
    Singleton* singleInstance = Singleton::getInstance();
    if(singleInstance != NULL)
        cout << "it worked" << endl;
}


