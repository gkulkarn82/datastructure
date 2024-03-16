/*
Variadic templates
The ... syntax creates a parameter pack or expands one. 
A template parameter pack is a template parameter that accepts zero or more template arguments 
(non-types, types, or templates). 
A template with at least one parameter pack is called a variadic template.

template <typename... T>
struct arity {
  constexpr static int value = sizeof...(T);
};
static_assert(arity<>::value == 0);
static_assert(arity<char, short, int>::value == 3);


An interesting use for this is creating an initializer list from a parameter pack in order to iterate over variadic function arguments.

template <typename First, typename... Args>
auto sum(const First first, const Args... args) -> decltype(first) {
  const auto values = {first, args...};
  return std::accumulate(values.begin(), values.end(), First{0});
}

sum(1, 2, 3, 4, 5); // 15
sum(1, 2, 3);       // 6
sum(1.5, 2.0, 3.7); // 7.2

Variadic templates in C++ are a powerful feature introduced in C++11 that allow you to create functions and classes 
that can accept a variable number of template arguments. 
This enables you to write more flexible and generic code that can work with a different number of arguments of various types. 
Variadic templates are particularly useful for creating containers, functions, and classes that need to handle a variable number of elements or types.

*/

#include <iostream>

// Base case: print the last argument
void printArgs() {
    std::cout << std::endl;
}

// Recursive case: print the current argument and call printArgs again for the remaining arguments
template <typename T, typename... Args>
void printArgs(T&& first, Args&&... args) {
    std::cout << first << " ";
    printArgs(std::forward<Args>(args)...);
}

int main() {
    printArgs(1, 2.3, "Hello", 'a');
    return 0;
}

/*
In this example, printArgs is a variadic template function that uses recursion to print each argument one by one. 
The base case is an empty function, and the recursive case prints the first argument and then calls itself with the remaining arguments.

Variadic templates are also commonly used in creating generic containers like std::tuple and in writing functions that 
take a variable number of arguments
*/

