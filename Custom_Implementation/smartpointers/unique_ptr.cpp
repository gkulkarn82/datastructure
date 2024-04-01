/*
    Implementation of smart pointers

    1. implement unique pointer
    2. default and parameterised constructor
    3. move constructor and move assignment operator
    4. it is not copyable and assinable 
    5. implementation of opertor * , -> and operator bool
    6. Distructor
    7. implement release , get , reset and swap
*/

#include<bits/stdc++.h>
using namespace std;

namespace own
{
    template<class T>
    class unique_ptr
    {
        public:           
            explicit unique_ptr(T* ptr = nullptr) noexcept : _ptr(ptr) {}
            unique_ptr(const unique_ptr& sourceptr) = delete;
            unique_ptr& operator=(const unique_ptr& sourceptr) = delete;

            unique_ptr(const unique_ptr&& source) noexcept : _ptr(std::move(source._ptr)) {
                source._ptr = nullptr;
            }

            //both implementation are correct for move constructor
            // unique_ptr(const unique_ptr&& source): _ptr(nullptr) {
            //     this->swap(source);             
            // }

            void swap(const unique_ptr& source) noexcept
            {
                std::swap(this._ptr, source._ptr);
            }

            unique_ptr& operator=(const unique_ptr&& source) noexcept
            {
                if(this != &source)
                {
                    unique_ptr temp(std::move(source));
                    this->swap(temp);
                }  
                return *this;
            }

            ~unique_ptr()
            {
                if(this->_ptr)
                   delete _ptr;
            }

            T& operator*() const noexcept
            {
                return *_ptr;
            }

            T* operator->() const noexcept
            {
                return _ptr;
            }

            operator bool() noexcept
            {
                return (_ptr != nullptr) ;
            }

            [[nodiscard]]
            T* release() noexcept
            {
                T* temp = this->_ptr; 
                this->_ptr = nullptr ;           
                return temp;
            }

            // void reset(T* p = nullptr)
            // {
            //     if(this->_ptr)
            //         delete _ptr;
            //     this->_ptr = p;
            // }

            void reset(T* p = nullptr) noexcept
            {
                unique_ptr uptr(p);
                this->swap(uptr);
            }

            T* get() const noexcept
            {
                return _ptr;
            }

        private:
            T* _ptr;
    };
};

class Employee
{
    public:
        Employee(string name, int age):_name(name),_age(age)
        {}
        ~Employee()
        {
            cout << "Employee destructor called " << endl;
        }
        string getName()
        {
            return _name;
        }
        int getAge()
        {
            return _age;
        }
    private:
        string _name;
        int _age;
};
int main()
{
    own::unique_ptr<int> i(new int(10));
    *i = 20;
    cout << "value of i =" << *i << endl;
    own::unique_ptr<Employee> emp(new Employee("Test",25));
    cout << "employee name = " << emp->getName() << " employee age " << emp->getAge() << endl;

    return 0;
}

