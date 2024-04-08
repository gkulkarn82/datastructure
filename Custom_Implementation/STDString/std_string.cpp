/*
    Implementing the custom std::string class
    1.default and parameterised constructor
    2.copy constructor
    3.copy assignment operator
    4.move constructor
    5.move assignment
    6.operator +, operator << , operator +=
    7.size
    8.length	
    9.max_size
    10.resize
    11.capacity
    12.reserve
    13.clear
    14.empty
    15.shrink_to_fit
    16.operator[]
    17.at
    18.back
    19.front
    20.c_str
*/

#include<iostream>
#include<string.h>
using namespace std;

namespace own
{
    const unsigned short DEFAULT_CAPACITY = 10;
    const unsigned short MAX_SIZE = 1000;
    class String
    {
        public:
            explicit String(const char* ptr = nullptr) noexcept:
                    _size((ptr != nullptr) ? strlen(ptr) : 0),
                    _capacity((_size > 0) ? _size : DEFAULT_CAPACITY),
                    _ptrdata(new char[_capacity + 1])
            {
                cout << "Calling constructor " << endl;
                for(int i = 0 ; i < _size; ++i)
                {
                    _ptrdata[i] = ptr[i];
                }
                _ptrdata[_size] = '\0'; 
            }

            String(const String& source) noexcept :
                    _size(source._size),
                    _capacity(source._capacity),
                    _ptrdata(new char[source._capacity + 1])
            {
                cout << "Calling copy constructor " << endl;
                for(int i = 0; i < _size; ++i)
                {
                    _ptrdata[i] = source._ptrdata[i];
                }
                _ptrdata[_size] ='\0';              
            }

            String& operator=(String& source) noexcept
            {
                cout << "Calling assignment operator " << endl;
                if(this != &source)
                {
                    String temp(source);
                    this->swap(temp);
                }
                return *this;
            }

            char& operator[](size_t index) const noexcept
            {
                return *this->_ptrdata[index];
            }

            char& at(std::size_t index) const noexcept
            {
                if(index >= size())
                    throw("Index out of bound exception");
                
                return (*this->_ptrdata)[index] ;//this->operator[](index); //this->m_ptr[index];
            }

            char* c_str() const noexcept
            {
                return this->_ptrdata;
            }

            char& back() const noexcept
            {
                return *this->_ptrdata[size -1];
            }

            char& front() const noexcept
            {
                return *this->_ptrdata[0];
            }

            String(String&& source) noexcept :
                    _size(std::move(source._size)),
                    _capacity(std::move(source._capacity)),
                    _ptrdata(std::move(source._ptrdata))
            {
                cout << "Calling move constructor " << endl;
                source._ptrdata = nullptr;
                source._size = 0;
                source._capacity = 0;
            }

            String& operator=(String&& source) noexcept
            {
                cout << "Calling move assignment operator " << endl;
                if(this != &source)
                {
                    String temp(std::move(source));
                    this->swap(temp);
                }
                return *this;
            }

            void operator+=(const String& source) noexcept
            {
                cout << "Calling operator += " << endl;

                this->reserve(this->_size + source._size);
                strcat(this->_ptrdata, source._ptrdata);               
            }

            void reserve(size_t size)
            {
                if(_capacity >= size)
                    return;

                char* temp = new char[size + 1];
                int i = 0;
                for(i = 0 ; i < this->_size; ++i)
                {
                    temp[i] = this->_ptrdata[i];
                }
                temp[i] = '\0';

                if(this->_ptrdata)
                    delete[] this->_ptrdata;

                this->_ptrdata = temp;
                this->_capacity = size;
            }

            void shrink_to_fit() noexcept
            {                
                if(_capacity != _size)
                    _capacity = _size;                    
            }
             
            void resize(size_t size) noexcept
            {                
                if(size >= lenght())
                    return;

                this->_ptrdata[size] = '\0';
                this->_size = size;
            }           

            void resize(size_t size, char c)
            {                
                if(size > this->_capacity)
                {
                    reserve(size);
                    int i = this->_size;
                    for(; i < size; ++i )
                    {
                        this->_ptrdata[i] = c;
                    }                    
                }
                else
                {
                    resize(size);
                }   
            }

            void clear() noexcept
            {
                this->_ptrdata[0] ='\0';
                this->_size = 0;
            }

            size_t capacity() const noexcept
            {
                return this->_capacity;
            }

            size_t size() const noexcept
            {
                return this->_size;
            }

            size_t length() const noexcept
            {
                return this->size();
            }

            size_t max_size() const noexcept
            {
                return MAX_SIZE;
            }

            bool empty() const noexcept
            {
                return (this->_size == 0);
            }
           
            ~String() noexcept
            {
                cout << "Calling destructor " << endl;
                if(_ptrdata)
                    delete[] _ptrdata;
                _size = 0;
                _capacity = 0;                
            }

            friend ostream& operator<<(ostream& out, const String& source) noexcept;
             //"Gajanan" + String("Kulkarni")
            friend String operator+(const String& source1,const String& source2) noexcept;
            friend String operator+(const String& source1,const char* source2) noexcept;
            friend String operator+(const char* source1,const String& source2) noexcept;           


        private:           
            size_t _size;
            size_t _capacity;
            char* _ptrdata;

            void swap(String& source)
            {
                std::swap(this->_size, source._size);
                std::swap(this->_capacity, source._capacity);
                std::swap(this->_ptrdata, source._ptrdata);
            }
    };

    ostream& operator<<(ostream& out, const String& source) noexcept
    {
        if(source._ptrdata != nullptr)
            out << source._ptrdata << endl;
        else
            out << "Nothing to print object is empty" << endl;
        return out;
    }

    String operator+(const String& source1,const String& source2) noexcept
    {
        String temp(source1);
        temp += source2;
        return temp;       
    }

    String operator+(const String& source1,const char* ptrsource) noexcept
    {
        String temp(source1);
        temp +=own::String(ptrsource);    
        return temp;
    }

    String operator+(const char* ptrsource,const String& source2) noexcept
    {
        String temp(own::String {ptrsource});
        temp += source2;
        return temp;
    }
}

int main()
{
   
    own::String s("Hi");

    // own::String s1 = s;
    // std::cout << s << endl;
    // std::cout << s1 << endl;

    // own::String s3 = std::move(s1);
    // std::cout << s3 << endl;
    // std::cout << s1 << endl;

    s.reserve(100);
    std::cout << s.capacity() << endl;

    std::cout << s + " Gajanan" << endl;
    //std::cout << s << endl;


    return 0;
}