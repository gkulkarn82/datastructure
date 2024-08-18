#include<iostream>
using namespace std;

namespace own
{  
    class Integer {
        public:
            // Default constructor
            Integer() : value_ptr(new int(0)) {
                std::cout << "Default constructor called" << std::endl;
            }

            // Parameterized constructor
            Integer(int val) : value_ptr(new int(val)) {
                std::cout << "Parameterized constructor called" << std::endl;
            }

            // Copy constructor
            Integer(const Integer& other) : value_ptr(new int(*other.value_ptr)) {
                std::cout << "Copy constructor called" << std::endl;
            }

            // Move constructor
            Integer(Integer&& other) noexcept : value_ptr(std::move(other.value_ptr)) {
                other.value_ptr = nullptr; // Nullify the other object's pointer to avoid double deletion
                std::cout << "Move constructor called" << std::endl;
            }

            // Destructor
            ~Integer() {
                delete value_ptr;
                std::cout << "Destructor called" << std::endl;
            }

            void swap(Integer& source)
            {
                std::swap(this->value_ptr, source.value_ptr);
            }

            // Copy assignment operator
            Integer& operator=(const Integer& other) {
                if (this != &other) {
                    Integer tmp(other);
                    this->swap(tmp);                  
                }             
                std::cout << "Copy assignment operator called" << std::endl;
                return *this;
            }

            // Move assignment operator
            Integer& operator=(Integer&& other) noexcept {
                if (this != &other) {
                    Integer tmp(std::move(other));
                    this->swap(tmp);
                    other.value_ptr = nullptr;
                }
                std::cout << "Move assignment operator called" << std::endl;
                return *this;
            }

            // Operator +
            Integer operator+(const Integer& rhs) const {
                return Integer(*value_ptr + *rhs.value_ptr);
            }

            // Pre-increment operator ++
            Integer& operator++() {
                ++(*value_ptr);
                return *this;
            }

            // Post-increment operator ++
            Integer operator++(int) {
                Integer temp(*this);
                ++(*value_ptr);
                return temp;
            }

            // << operator for output
            friend std::ostream& operator<<(std::ostream& os, const Integer& obj);           
        private:
            int* value_ptr; // Pointer to dynamically allocated integer
    };

    std::ostream& operator<<(std::ostream& os, const Integer& obj) {
        if(obj.value_ptr != nullptr)
                os << *obj.value_ptr;
        else
            cout << "Nothing to print" << endl;
        return os;
    }
}

int main() {
    // Testing the Integer class
    own::Integer a(5);
    own::Integer b(3);

    std::cout << "a = " << a << std::endl; // a is moved from, so this will output an undefined value
    std::cout << "b = " << b << std::endl; // b is moved from, so this will output an undefined value

    own::Integer c = std::move(a); // Move constructor
    own::Integer d; 
    d = std::move(b); // Move assignment operator

    std::cout << "a = " << a << std::endl; // a is moved from, so this will output an undefined value
    std::cout << "b = " << b << std::endl; // b is moved from, so this will output an undefined value
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    ++c; // Pre-increment
    d++; // Post-increment

    std::cout << "c after pre-increment = " << c << std::endl;
    std::cout << "d after post-increment = " << d << std::endl;

    own::Integer e = c + d; // Operator +
    std::cout << "c + d = " << e << std::endl;

    return 0;
}