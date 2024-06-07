 /*
Heretogeneous vector using variant
Heterogenious vector means a vector who can store any data type in one object

What is heterogenious vector ?
    Vector is a STL container which  keep data with similar data type
    e.g vector<int> , vector<char> 
    if we want to use vector which can accept differnt data types in same vector
What is std::variant ?
    std::variant is introduce in C++17 it can have value with different type
*/

#include<iostream>
#include<vector>
#include<variant>
#include<string>
using namespace std;

class Student
{
    public:
        Student(const std::string& name, const unsigned short& age) noexcept : _name(name) , _age(age)
        {

        }

        void print() const noexcept
        {
            std::cout << "Student Name : " << _name << " Age: " << _age << endl;
        }
    private:
        std::string _name;
        unsigned short _age;
};

using HeterogeneousVector = std::vector<std::variant<int , double, std::string, Student>>;
using HeretogeneousElement = std::variant<int , double, std::string, Student>;

void Print(const HeretogeneousElement& var) 
{
    // if (var.index == 0)
    // {
    //     std::cout << "Int: " << std::get<int>(var) << endl;
    // }
    // else if(1 == var.index)
    // {
    //     std::cout << "Double: " << std::get<double>(var) << endl;
    // }
    // else if(var.index == 2)
    // {
    //     std::cout << "String: " << std::get<std::string>(var) << endl;
    // }
    // else if(var.index == 3)
    // {
    //     std::get<Student>(var).print();
    // }

    //Alternate way using holds_alternative method
    if (std::holds_alternative<int>(var)) 
    {
        std::cout << std::get<int>(var) << std::endl;
    }
    else if (std::holds_alternative<double>(var)) 
    {
        std::cout << std::get<double>(var) << std::endl;
    }
    else if (std::holds_alternative<std::string>(var)) 
    {
        std::cout << std::get<std::string>(var) << std::endl;
    }
    else if (std::holds_alternative<Student>(var)) 
    {
        std::get<Student>(var).print();
    }

}

int main()
{
    HeterogeneousVector vect;
    vect.emplace_back(10);
    vect.emplace_back(10.10);
    vect.emplace_back("String");
    vect.emplace_back(Student("Raj",22));

    for(const auto& element : vect)
    {
        Print(element);
    }
    
    return 0;
}