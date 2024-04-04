#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Less
{
    constexpr bool operator()(T a, T b)
    {
        return (a < b);
    }
};

void Test()
{
    cout << "This is function call for TEST " << endl;
}

int main()
{
    Less<double> l1;
    void (*func)() = &Test;   
    
    func();
    cout << boolalpha << l1(10.43,20.33) << endl;

    cout << "sizeof(func) = "<< sizeof(func) << " sizeof(l1) = " << sizeof(l1) << endl;
    return 0;
}