#include<iostream>
#include <cstring>

using namespace std;

namespace own
{
    template <typename T=char>
    class String {
    public:

        String();//default constructor
        explicit String(const T* s);

        MyString(const String& other); // copy constructor
        String& operator=(const String& other); //copy assignment operator
        
        String(String&& other) noexcept ; // move constructor
        String& operator=(String &&other) noexcept; //move assignment operator
        
        String operator+(const String& other); // concatenation
        ~String() = default;
        
        /*
            "nodiscard" is a standard library feature in C++11 that eliminates unused variables by decorating a function call 
            with the "nodiscard" specifier. This ensures that the compiler reminds developers to use the returned value of the function,
            thus avoiding waste of resources and improving code maintainability. It did not become widely used, and was removed in C++20.    
        */
        [[nodiscard]] const T* c_str() const;
        [[nodiscard]] size_t length() const;

        friend std::ostream& operator<<(std::ostream& os, const String<T>& mystring);

        void swap(String<T>& source)
        {
            std::swap(this->d_data_p, source.d_data_p);
            std::swap(this->d_size, source.d_size);
        }

    private:
        T* d_data_p;
        size_t d_size;
    };

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const String<T>& mystring)
    {
        return os << mystring.c_str();
    }

    //default constructor
    template <typename T>
    String<T>::String() : d_data_p(nullptr), d_size(0) {

    }

    //parameterised constructor
    template <typename T>
    String<T>::String(const T* str):d_data_p(const_cast<T*>(str))
    {
        if(d_data_p == nullptr)
        {
            d_size = 0;
        }
        else
        {
            d_size = strlen(d_data_p);
        }
        
    }

    //copy constructor
    template <typename T>
    String<T>::String(const MyString &other) : d_data_p(other.d_data_p), d_size(other.d_size) {

    }

    //assignment operator overload
    template <typename T>
    String<T>& String<T>::operator=(const MyString<T> &other) {
        // d_data_p = other.d_data_p;
        // d_size = other.d_size;
        // return *this;
        if(this != &other)
        {
            String<T> temp(other);
            this->swap(temp);
        }
        return *this;
    }

    template <typename T>
    const T *String<T>::c_str() const {
        return d_data_p;
    }

    //move assignment operator overaload
    template <typename T>
    String<T> &String<T>::operator=(String<T>&& other) noexcept
    {       
        if(this != &other)
        {
            String<T> temp(std::move(other));
            this->swap(temp);
        }
        return *this;
    }

    //move constructor
    template <typename T>
    String<T>::String(MyString<T> &&other) noexcept :
                    d_data_p(std::move(other.d_data_p)), 
                    d_size(std::move(other.d_size)) 
     {      
        other.d_data_p = nullptr;
        other.d_size = 0;
    }

    template <typename T>
    size_t String<T>::length() const {
        return d_size;
    }

    template <typename T>
    String<T> String<T>::operator+(const MyString<T> &other) {
        MyString s; // create a new string named 's'
        s.d_size = this.d_size + other.d_size;
        s.d_data_p = static_cast<char *>(malloc(s.d_size + 1));
        s.d_data_p = strcpy(s.d_data_p, this.d_data_p); // technically it should only for char, possibly find a better way?
        s.d_data_p = strcat(s.d_data_p, other.d_data_p); // technically it should only for char,  possibly find a better way?
        return s;
    }
}

