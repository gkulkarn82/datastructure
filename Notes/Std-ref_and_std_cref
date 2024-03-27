/*
std::ref, std::cref

Function templates ref and cref are helper functions that generate an object of type std::reference_wrapper, 
using template argument deduction to determine the template argument of the result.

Parameters
t	-	lvalue reference to object that needs to be wrapped or an instance of std::reference_wrapper
Return value
1) std::reference_wrapper<T>(t)
2) t
4) std::reference_wrapper<const T>(t)
5) t
3,6) rvalue reference wrapper is deleted.

std::ref()  creates the genral reference vairable or of type reference
std::cref() create a const ref of the variable or of type const reference

*/

#include <functional>
#include <iostream>
 
void f(int& n1, int& n2, const int& n3)
{
    std::cout << "In function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
    ++n1; // increments the copy of n1 stored in the function object
    ++n2; // increments the main()'s n2
    
    //This is a compiler error because n3 is sent as std::cref which means it is constant
    //hence incrementing constant value will lead to compiler error
    // ++n3; // compile error
}
 
int main()
{
    int n1 = 1, n2 = 2, n3 = 3;
    //The bind function binds the parameter and to the functions
    //so even though bound_f is called later in this code but it will accept the value which is bound earlier 
    //and will not pick the value which are changed later after the bind is called

    //e.g before bind the value of n1 = 1, n2 = 2, n3 = 3
    //after bind the value of n2 changed to 11 and n3 to 12 since they are sent as reference they will 
    //pick the updated value as 11 and 12 to the function/

    // as before the function call the value has changed
    std::function<void()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));
    n1 = 10;
    n2 = 11;
    n3 = 12;
    std::cout << "Before function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
    bound_f();
    std::cout << "After function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
}

/*
Output:

Before function: 10 11 12
In function: 1 11 12
After function: 10 12 12

Meaning:
    The vlaue of n1 was previously 1 which is bound to the function and n1 is sent as copy
    so even though value has changed it will still consider 1 as the bound value

*/