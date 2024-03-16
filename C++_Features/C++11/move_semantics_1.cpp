#include<iostream>
#include<memory>

using namespace std;

int main()
{
    auto ptr1 = std::make_unique<int[]>(10);
    std::cout << "ptr1 before move " << ptr1.get() << endl;
    //unique pointers can not be copied or  
    //copy constructor for the unique pointer does not exists
    //hence there will be an error that use of deleted copy constructor 
    // e.g  unique_ptr(const unique_ptr&) = delete;

    //auto ptr2 = ptr1

    //After using move contructor
    auto ptr2 = std::move(ptr1);
    std::cout << "ptr1 after move " << ptr1.get() << endl;
    std::cout << "ptr2 before move " << ptr2.get() << endl;
    return 0;
}