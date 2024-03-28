#include<bits/stdc++.h>
using namespace std;

class Singleton
{
public:    
    static Singleton& getInstance()
    {
        //static object creation effectively atomic operation
        static Singleton obj;
        return obj;
    }
private:   
    Singleton() = default;
    Singleton(const Singleton& obj) = delete;
    Singleton& operator=(const Singleton& source) = delete;
    Singleton(Singleton&& obj) = delete;
    Singleton& operator=(const Singleton&& source) = delete;
    ~Singleton() = default;
};

int main()
{  
    Singleton& obj = Singleton::getInstance();
    return 0;
}