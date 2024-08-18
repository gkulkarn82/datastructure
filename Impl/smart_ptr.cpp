#include<iostream>
using namespace std;

namespace smartpointer
{
    template<class T>
    class pointer
    {
        public:
            explicit Pointer(T* ptr):_ptr(ptr)
            {}
            Pointer(const Pointer& source) = delete;
            Pointer& operator=(Pointer& source) = delete;

            // Pointer(const Pointer&& source) = delete;
            // Pointer& operator=(Pointer&& source) = delete;
            T& operator *()
            {
                return *this->_ptr;
            }

            T* operator ->()
            {
                return this->_ptr;
            }

            ~Pointer()
            {
                if(this->_ptr)
                    delete _ptr;
            }
        private:
            T* _ptr;
    };
}