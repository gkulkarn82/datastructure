#include<bits/stdc++.h>
using namespace std;

class Base
{
protected:
    void test()
    {
        cout <<"Test protected" << endl;;
    }
};

class Deerived : public Base
{
public:
    void f()
    {
        cout << "public derived" << endl;
        test();
    }
    using Base::test;
};

int main()
{
    Base b;
    //b.test();
    Deerived d;
    d.f();
    d.test();
    getchar();
    return 0;
}