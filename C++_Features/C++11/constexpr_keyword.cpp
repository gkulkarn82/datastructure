/*
constexpr
Constant expressions are expressions that are possibly evaluated by the compiler at compile-time. Only non-complex computations can be carried out in a constant expression (these rules are progressively relaxed in later versions). Use the constexpr specifier to indicate the variable, function, etc. is a constant expression.

constexpr int square(int x) {
  return x * x;
}

int square2(int x) {
  return x * x;
}

int a = square(2);  // mov DWORD PTR [rbp-4], 4

int b = square2(2); // mov edi, 2
                    // call square2(int)
                    // mov DWORD PTR [rbp-8], eax
In the previous snippet, notice that the computation when calling square is carried out at compile-time, and then the result is embedded in the code generation, while square2 is called at run-time.

constexpr values are those that the compiler can evaluate, but are not guaranteed to, at compile-time:

const int x = 123;
constexpr const int& y = x; // error -- constexpr variable `y` must be initialized by a constant expression
Constant expressions with classes:

struct Complex {
  constexpr Complex(double r, double i) : re{r}, im{i} { }
  constexpr double real() { return re; }
  constexpr double imag() { return im; }

private:
  double re;
  double im;
};

constexpr Complex I(0, 1);

if we make anything variable or functions constexpr then they get evaluated compile time and not at run time saving time 
and performing optimization.
*/

#include<iostream>
using namespace std;

//constexpr functions
constexpr int foo(int a)
{
    return a * 3;
}

int func1(int b)
{
    return b * 2;
}

int x = 4;
constexpr int func(int a)
{
    //return a * func1(3); // this will lead to error as nonconstexpr is called from within constexpr
    // error: call to non-‘constexpr’ function ‘int func1(int)’
    //same is true for functions as well as variables

    return x * 3 ; //will fail as x is nonconstexpr

} 



int foo1(int b)
{
    return b * 2;
}

int main()
{
    constexpr int x = 5 + 2 ;// gets executed or evaludated at compiler time
    const int y = 5 + 2; // this will get executed at run time
    int z = 5 + 2;

    int arr[x] ; // this will work as x is evaludated at compiletime
    int a[z]; //Error: will not work because c++ do not allow variable as size declrator which will be evaluated at runtime 

    int c[foo(4)] ; // since foo gets evaluated at compile time hence assigning works;
    int d[foo1(2)];
}