/*
std::tie is a utility function provided by the Standard Library (in the tuple header) 
that allows you to create a tuple of references to multiple variables. 
It is often used in conjunction with std::tuple to easily unpack the elements of a tuple or a structure into individual variables. 
This is particularly useful when working with functions that return multiple values as a tuple or when you want to assign 
multiple values to different variables in a concise way.

*/
#include <iostream>
#include <tuple>

int main() {
    int a = 1;
    double b = 2.3;
    std::string c = "Hello";

    // Creating a tuple of references to variables a, b, and c
    std::tie(a, b, c) = std::make_tuple(42, 7.89, "World");

    // Now, the values of a, b, and c have been updated
    std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;

    return 0;
}
