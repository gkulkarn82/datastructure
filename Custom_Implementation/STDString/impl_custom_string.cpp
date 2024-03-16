#include<iostream>
#include <cstring>

using namespace std;

template <typename T=char>
class MyString {
public:

    MyString();//default constructor
    explicit MyString(const T* s);

    MyString(const MyString& other); // copy constructor
    MyString& operator=(const MyString& other); //copy assignment operator
    
    MyString(MyString&& other) noexcept ; // move constructor
    MyString& operator=(MyString &&other) noexcept; //move assignment operator
    
    MyString operator+(const MyString& other); // concatenation
    ~MyString() = default;
    
    /*
        "nodiscard" is a standard library feature in C++11 that eliminates unused variables by decorating a function call 
        with the "nodiscard" specifier. This ensures that the compiler reminds developers to use the returned value of the function,
        thus avoiding waste of resources and improving code maintainability. It did not become widely used, and was removed in C++20.    
    */
    [[nodiscard]] const T* c_str() const;
    [[nodiscard]] size_t length() const;
    
private:
    T* d_data_p;
    size_t d_size;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const MyString<T>& mystring)
{
    return os << mystring.c_str();
}

template <typename T>
MyString<T>::MyString() : d_data_p(nullptr), d_size(0) {

}

template <typename T>
MyString<T>::MyString(const T* str):d_data_p(const_cast<T*>(str))
{
    if(d_data_p == nullptr)
    {
        d_size = 0;
    }
    else{
        d_size = strlen(d_data_p);
    }
    
}

//copy constructor
template <typename T>
MyString<T>::MyString(const MyString &other) : d_data_p(other.d_data_p), d_size(other.d_size) {

}

//assignment operator overload
template <typename T>
MyString<T> &MyString<T>::operator=(const MyString<T> &other) {
    d_data_p = other.d_data_p;
    d_size = other.d_size;
    return *this;
}

template <typename T>
const T *MyString<T>::c_str() const {
    return d_data_p;
}

//move assignment operator overaload
template <typename T>
MyString<T> &MyString<T>::operator=(MyString<T> &&other) noexcept {
    d_data_p = other.d_data_p;
    d_size = other.d_size;
    other.d_data_p = nullptr;
    other.d_size = 0;
    return *this;
}

//move constructor
template <typename T>
MyString<T>::MyString(MyString<T> &&other) noexcept {
    d_data_p = other.d_data_p;
    d_size = other.d_size;
    other.d_data_p = nullptr;
    other.d_size = 0;
}

template <typename T>
size_t MyString<T>::length() const {
    return d_size;
}

template <typename T>
MyString<T> MyString<T>::operator+(const MyString<T> &other) {
    MyString s; // create a new string named 's'
    s.d_size = this.d_size + other.d_size;
    s.d_data_p = static_cast<char *>(malloc(s.d_size + 1));
    s.d_data_p = strcpy(s.d_data_p, this.d_data_p); // technically it should only for char, possibly find a better way?
    s.d_data_p = strcat(s.d_data_p, other.d_data_p); // technically it should only for char,  possibly find a better way?
    return s;
}

