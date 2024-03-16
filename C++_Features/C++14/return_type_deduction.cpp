/*
Return Type Deduction
Using an auto return type in C++14, the compiler will attempt to deduce the type for you. With lambdas, you can now deduce its return type using auto, which makes returning a deduced reference or rvalue reference possible.

// Deduce return type as `int`.
auto f(int i) {
 return i;
}
template <typename T>
auto& f(T& t) {
  return t;
}

// Returns a reference to a deduced type.
auto g = [](auto& x) -> auto& { return f(x); };
int y = 123;
int& z = g(y); // reference to `y`

decltype(auto)
The decltype(auto) type-specifier also deduces a type like auto does. However, it deduces return types while keeping their references and cv-qualifiers, while auto will not.

const int x = 0;
auto x1 = x; // int
decltype(auto) x2 = x; // const int
int y = 0;
int& y1 = y;
auto y2 = y1; // int
decltype(auto) y3 = y1; // int&
int&& z = 0;
auto z1 = std::move(z); // int
decltype(auto) z2 = std::move(z); // int&&
// Note: Especially useful for generic code!

// Return type is `int`.
auto f(const int& i) {
 return i;
}

// Return type is `const int&`.
decltype(auto) g(const int& i) {
 return i;
}

int x = 123;
static_assert(std::is_same<const int&, decltype(f(x))>::value == 0);
static_assert(std::is_same<int, decltype(f(x))>::value == 1);
static_assert(std::is_same<const int&, decltype(g(x))>::value == 1);

*/

#include<iostream>
using namespace std;

auto add(int x, int y){ return x + y;};
auto& incremental(int& a){a++; return a;}

/*
    if we are trying ti get the reference then just writting auto won't work in C++14
    we need to write somethig called as decletype(auto) incremental(int& a){a++; return a;}

    but in my current case it is working as i have c++ 20 compiler and this might have been removed in c++20

*/
int main()
{
    int p = 10;
    int& y = incremental(p);
    cout << p << endl;
    cout << y << endl;

    const int x = 0;
    auto x1 = x; // int this is int but if we want it to be const int then we need to use decletype to get the exact understanding
    decltype(auto) x2 = x; // const int
    int y = 0;
    int& y1 = y;
    auto y2 = y1; // int
    decltype(auto) y3 = y1; // int&
    int&& z = 0;
    auto z1 = std::move(z); // int
    decltype(auto) z2 = std::move(z); // int&&
    // Note: Especially useful for generic code!

    cin.get();
    return 0;
}