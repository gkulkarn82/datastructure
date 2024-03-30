/*
    Implementation of sizeof operator
    1. function of which return size
    2. int* ptr let say ptr is poited to memory location 100
    3. int* ptr1 = ptr + 1 ptr will point to memory location 104

    4. char* ptr let say ptr is poited to memory location 100
    5. char* ptr1 = ptr + 1 ptr will point to memory location 101

    6. node* ptr let say ptr is poited to memory location 100
    7. node* ptr1 = ptr + 1 ptr will point to memory location 100 + sizeof(node)
    
*/
#include<iostream>
using namespace std;

template<class T>
size_t my_sizeof(T& object) 
{
    T* ptr = &object;
    T* ptr1 = ptr + 1;
    cout << "Before ptr 1- ptr = " << ptr1 - ptr << endl;
    std::size_t size = reinterpret_cast<char*> (ptr1) - reinterpret_cast<char*> (ptr);
    return  size;
}

int main()
{
    int i = 10;
    float f = 12.23;
    double d= 32.3455;
    char ch = 'c';

    cout << "size of int " << my_sizeof(i) << endl;
    cout << "size of float " << my_sizeof(f) << endl;
    cout << "size of double " << my_sizeof(d) << endl;
    cout << "size of char " << my_sizeof(ch) << endl;

    return 0;
}

/*
    O/P
    size of int Before ptr 1- ptr = 1
    4
    size of float Before ptr 1- ptr = 1
    4
    size of double Before ptr 1- ptr = 1
    8
    size of char Before ptr 1- ptr = 1
    1

    ptr1 = ptr + 1
    ptr1 - ptr = 1 this is simple

    Now lets talk in terms of memory locationn when we add + 1 to memory location lets see what happens

    e.g 
    int* ptr , ptr1 // now ptr is pointing to 100 and ptr1 is pointing to 104
    when we take difference it will check the difference based on type since both are int the differance is only of 1 place

    But to calculate actual size if we use char which is of 1 byte the when we do the minus operation then this difference will be calcualted
    based on char or bytes difference of 1 then it will give the difference of 4 and not 1. same is true for all the data type.
*/

