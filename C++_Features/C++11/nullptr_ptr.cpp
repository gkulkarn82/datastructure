/*
nullptr
C++11 introduces a new null pointer type designed to replace C's NULL macro. 
nullptr itself is of type std::nullptr_t and can be implicitly converted into pointer types, 
and unlike NULL, not convertible to integral types except bool.

void foo(int);
void foo(char*);
foo(NULL); // error -- ambiguous
foo(nullptr); // calls foo(ch

*/

#include<iostream>
using namespace std;

void fun(int x) {};
void bar(char *C){};

int main()
{
    // NULL is equal to 0
   // int x = NULL;
   // cout << NULL << endl; // it is replacement for 0

    // Above is an older way with new way it is not possible

    //int y = nullptr; // error: cannot convert ‘std::nullptr_t’ to ‘int’ in initialization
    cout << nullptr << endl;// it treats it as string
    cout << nullptr + 3 << endl; ; //error: invalid operands of types ‘std::nullptr_t’ and ‘int’ to binary ‘operator+’

    fun(NULL);
    bar(NULL);

    fun(nullptr);
    bar(nullptr);
}