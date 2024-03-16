/*
Explicit virtual overrides
Specifies that a virtual function overrides another virtual function. If the virtual function does not override a parent's virtual function, throws a compiler error.

struct A {
  virtual void foo();
  void bar();
};

struct B : A {
  void foo() override; // correct -- B::foo overrides A::foo
  void bar() override; // error -- A::bar is not virtual
  void baz() override; // error -- B::baz does not override A::baz
};


Final specifier
Specifies that a virtual function cannot be overridden in a derived class or that a class cannot be inherited from.

struct A {
  virtual void foo();
};

struct B : A {
  virtual void foo() final;
};

struct C : B {
  virtual void foo(); // error -- declaration of 'foo' overrides a 'final' function
};
Class cannot be inherited from.

struct A final {};
struct B : A {}; // error -- base 'A' is marked 'final'

*/

#include<iostream>
using namespace std;

class Foo
{
    public:
        // final keyword do not allow to inherit it further
        virtual void print() final
        {
            cout << "Hello" << endl;
        }

        virtual void foo(int x) 
        {
            cout << x << endl;
        }
};

class Bar : Foo
{
    public:
        // void print()
        // {
        //     cout << "Goodbye !!!" << endl;
        // }

        //without override keyword this function works fine
        //but after adding override keyword it says that there is no function
        // with double as parameter hence this is not override method 
        // so basically it the keyword strictly checks the override rules
        void foo(double x) 
        {
            cout << x * x << endl;
        }

        void foo(int  x) override
        {
            cout << x * x << endl;
        }
};

int main()
{
    // Foo f;
    // f.print();

    // Bar b;
    // b.print();

    Bar b;
    b.foo(3);

    cin.get();
    return 0;
}
