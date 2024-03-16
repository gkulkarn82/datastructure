/*
Lambda expressions
A lambda is an unnamed function object capable of capturing variables in scope. It features: a capture list; an optional set of parameters with an optional trailing return type; and a body. Examples of capture lists:

[] - captures nothing.
[=] - capture local objects (local variables, parameters) in scope by value.
[&] - capture local objects (local variables, parameters) in scope by reference.
[this] - capture this by reference.
[a, &b] - capture objects a by value, b by reference.
int x = 1;

auto getX = [=] { return x; };
getX(); // == 1

auto addX = [=](int y) { return x + y; };
addX(1); // == 2

auto getXRef = [&]() -> int& { return x; };
getXRef(); // int& to `x`
By default, value-captures cannot be modified inside the lambda because the compiler-generated method is marked as const. The mutable keyword allows modifying captured variables. The keyword is placed after the parameter-list (which must be present even if it is empty).

int x = 1;

auto f1 = [&x] { x = 2; }; // OK: x is a reference and modifies the original

auto f2 = [x] { x = 2; }; // ERROR: the lambda can only perform const-operations on the captured value
// vs.
auto f3 = [x]() mutable { x = 2; }; // OK: the lambda can perform any operations on the captured value


*/

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main()
{

    //call the function directly
    [] {cout << "Hello World !!!" << endl; } ();

    //assign lambda to a veriable
    auto p =[] {cout << "Goodbye !!!" << endl ;};
    //call it
    p();

    //add parameter list to the lambda
    auto q = [] (int a, int b){ cout << a+ b << endl ;} ;
    q(1, 3);

    //lambda can return value
    auto r = [] (int a, int b) {return a + b ;};
    int x = r(1, 3);
    cout << x << endl;
    cout << r(5,3) << endl;

    auto s = [] (int a, int b)-> int {return a + b;};
    cout << s(9, 10) << endl; 

    vector<int> v {8, 6, 7, 5, 3, 0 , 9};
    sort(v.begin(), v.end(), [](int a, int b)-> bool {return a < b ;});

    for(int i : v)
        cout << i << " ";
    cout << endl;

    //captures  -- access to the outer scope
    int x1 = 4, y = 3;
    auto t = [x1 , &y]
    {
        cout << x1 << endl;
        cout << y++ << endl;
    };
    t();

    cout << y << endl;

    cin.get();
    return 0;



}