#include <cstring>
#include <iostream>

class customstring {
private:
    char* data;
    size_t length;

public:
    customstring(const char* str = "") 
	{
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }
	
    ~customstring() 
	{
        delete[] data;
    }

    //copy constructor
    customstring(const customstring& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    //overloaded assignment operator
    customstring& operator=(const customstring& other)
	{
        if (this != &other) 
		{
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    //overloaded operator for concatenation
    customstring operator+(const customstring& other) const 
	{
        customstring result;
        result.length = length + other.length;
        result.data = new char[result.length + 1];
        strcpy(result.data, data);
        strcat(result.data, other.data);
        return result;
    }

    //get the string len 
    size_t size() const 
	{
        return length;
    }

    //c_str() implementation
    const char* c_str() const 
	{
        return data;
    }

    //overloading of << operator for printing
    friend std::ostream& operator<<(std::ostream& output, const customstring& str) 
	{
        output << str.data;
        return output;
    }
};

int main() {
	//initialization
    customstring str1("Test");
    customstring str2(" customstring");

    customstring result = str1 + str2;

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "concatenated string result: " << result << std::endl;

    return 0;
}

