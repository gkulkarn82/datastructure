/*
Deleted functions
A more elegant, efficient way to provide a deleted implementation of a function. Useful for preventing copies on objects.

class A {
  int x;

public:
  A(int x) : x{x} {};
  A(const A&) = delete;
  A& operator=(const A&) = delete;
};

A x {123};
A y = x; // error -- call to deleted copy constructor
y = x; // error -- operator= deleted

*/

#include<iostream>
using namespace std;

class Foo
{
    private:
        int x;
    public:
        Foo(): x(0) {}
        Foo(int y)  { x = y;}
        Foo(double y) = delete;
        Foo(const Foo& ) = delete;
        Foo& operator=(const Foo&) = delete;
        void* operator new(size_t) = delete;
};

int main()
{
    Foo f;

    Foo g(f) ; // not allowed as copy constructor is deleted;

    Foo g;

    f = g ; //not allowed as = operator is deleted

    return 0;
}