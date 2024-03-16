/*
decltype is an operator introduced in C++11 that allows you to determine and specify the type of an expression or an entity without 
actually evaluating the expression. It is useful in scenarios where you want to deduce or declare the type of something based 
on an existing expression or variable. decltype is often used in conjunction with templates, auto, and metaprogramming techniques 
to write more generic and type-safe code.
*/

#include<iostream>
using namespace std;

// for metaprogramming return of add will be deduce based on x and y type
/*
In this function template, the return type is deduced using decltype, 
which allows the function to return the appropriate type based on the types of its arguments.
*/
template <typename T, typename U>
auto add(T x, U y) -> decltype(x + y) {
    return x + y;
}

int foo() {}
double bar() {}

int main()
{
    int x = 42;
    decltype(x) y; // y has the same type as x, which is int
    // here we have identified the type of x which is int and declare the variable with same type i.e 
    //decltype(x) y means int y;

    int a = 5, b = 10;
    decltype(a + b) result;
    cout << decltype(result) << endl;

    decltype(foo()) result1; // result1 has the type of the return value of foo(), which is int
    decltype(bar()) result2; // result2 has the type of the return value of bar(), which is double
}