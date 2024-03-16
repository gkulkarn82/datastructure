/*
1 . Type aliases
Semantically similar to using a typedef however, type aliases with using are easier to read and are compatible with templates.

template <typename T>
using Vec = std::vector<T>;
Vec<int> v; // std::vector<int>

using String = std::string;
String s {"foo"};

2. Attributes
Attributes provide a universal syntax over __attribute__(...), __declspec, etc.


3. Noexcept specifier
The noexcept specifier specifies whether a function could throw exceptions. It is an improved version of throw().

4. Default Functions
A more elegant, efficient way to provide a default implementation of a function, such as a constructor.

*/

#include<iostream>
using namespace std;


/*
EXAMPLE : Type allises

instead of typedef use using keyword

*/

template <typename T>
using Vec = std::vector<T>;
Vec<int> v; // std::vector<int>

using String = std::string;
String s {"foo"};

/*
EXAMPLE : Attributes
instead of mentioning _declespec
*/

/*
[[noreturn]]: This attribute indicates that a function does not return to its caller. 
It is often used with functions like exit() or functions that throw exceptions.
*/
[[noreturn]] void exit_program() {
    // ...
    std::exit(0);
}

/*
[[deprecated]]: This attribute marks a function, class, or variable as deprecated, 
indicating that it should be avoided because it may be removed or replaced in the future. 
It helps developers migrate away from deprecated features gradually.
*/
[[deprecated("Use new_function() instead")]] void old_function() {
    // ...
}

/*
[[nodiscard]]: This attribute advises the compiler to issue a warning if the return value of a function is not used. 
It encourages developers to handle the return value properly.
*/
[[nodiscard]] int get_value() {
    return 42;
}

/*
EXAMPPLE: noexcept specifier
*/
void func1() noexcept;        // does not throw
void func2() noexcept(true);  // does not throw
void func3() throw();         // does not throw

void func4() noexcept(false); // may throw

/*
EXAMPLE: Default function
*/
/*
C++11 also introduced the default and delete keywords, which allow you to specify whether you want the compiler to generate 
default functions or prevent it from generating them.For example, you can use default to explicitly request a compiler-generated 
default function:
*/
class MyClass {
public:
    // Explicitly request a compiler-generated default constructor
    MyClass() = default;
};


int main()
{

}