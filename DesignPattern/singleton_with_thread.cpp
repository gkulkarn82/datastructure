#include<bits/stdc++.h>
using namespace std;

class Singleton
{
public:
    static Singleton* getInstance()
    {
        if(_instance == nullptr)
        {
            lock_guard<mutex> lock(_mu);
            if(_instance == nullptr)
            {
                _instance = new Singleton();
            }
        }
        return _instance;
    }    
private:
    static Singleton* _instance;
    static mutex _mu;
    Singleton() = default;
    Singleton(const Singleton& obj) = delete;
    Singleton& operator=(const Singleton& source) = delete;
    Singleton(Singleton&& obj) = delete;
    Singleton& operator=(const Singleton&& source) = delete;
    ~Singleton() = default;
};

Singleton* Singleton::_instance = nullptr;
mutex Singleton::_mu;

int main()
{
    Singleton* ptr = Singleton::getInstance();
    Singleton obj(*ptr);   
    return 0;
}