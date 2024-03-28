#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Employee
{
public:
    explicit Employee(const std::string& name = "", const int age = 0):_name(name),_age(age)
    {}
    friend ostream& operator<<(ostream& out,const Employee& emp);
private:
    string _name;
    int _age;
};

ostream& operator<<(ostream& out, const Employee& emp)
{
    out << "Employee Name = " << emp._name << " Employee Age = " << emp._age << endl;
    return out;
}

class IElement
{
public:
    virtual ~IElement(){}
    virtual void PrintVariant() = 0;
private:
};

template<class T>
class Element:public IElement
{
public:
    Element() = default;
    Element(T data): _data(data) { }

    Element(const Element& var) = default;
    Element& operator=(const Element& source) = default;

    Element(Element&& var) = default;
    Element& operator=(Element&& source) = default;

    ~Element() = default;

    void PrintVariant() override
    {
        cout << "data " << _data << endl;
    }
private:
    T _data;   
};

int main()
{
    vector<std::unique_ptr<IElement>> vect ;    
    vect.emplace_back(std::make_unique<Element<int>>(10));
    vect.emplace_back(std::make_unique<Element<double>>(10.25));
    vect.emplace_back(std::make_unique<Element<string>>("string"));
    Employee emp("Test", 23);

    vect.emplace_back(std::make_unique<Element<Employee>>(emp));

    for(auto& var : vect)
    {
        var->PrintVariant();
    }

    return 0;
}