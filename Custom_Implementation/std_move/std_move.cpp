#include <type_traits>

// Custom move implementation
template<typename T>
typename std::remove_reference<T>::type&& my_move(T&& arg) noexcept {
    return static_cast<typename std::remove_reference<T>::type&&>(arg);
}

// Example usage
#include <iostream>
#include <vector>

class MyClass {
public:
    MyClass(int data) : data_(data) {
        std::cout << "Constructor: " << data_ << std::endl;
    }

    MyClass(MyClass&& other) noexcept : data_(other.data_) {
        other.data_ = 0;  // Leave other in a valid state
        std::cout << "Move Constructor: " << data_ << std::endl;
    }

    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            data_ = other.data_;
            other.data_ = 0;  // Leave other in a valid state
            std::cout << "Move Assignment: " << data_ << std::endl;
        }
        return *this;
    }

    ~MyClass() {
        std::cout << "Destructor: " << data_ << std::endl;
    }

private:
    int data_;
};

int main() {
    MyClass obj1(42);
    MyClass obj2 = my_move(obj1);  // Use custom move

    // Move assignment
    MyClass obj3(100);
    obj3 = my_move(obj2);

    return 0;
}
