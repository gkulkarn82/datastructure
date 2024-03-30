/*
    Virtual Inheritance
*/

#include<bits/stdc++.h>
using namespace std;

class Base
{
public:
    virtual void print()
    {
        cout << "Print Of Base Class " << endl;
    }

    virtual ~Base()
    {
        cout << "Distructor Of Base " << endl;
    }

private:

};

class Derived : public Base
{
public:
    Derived()
    {
        i = new int(5);
    }

    void print() override 
    {
        cout << "Print Of Derived Class " << endl;
    }

    ~Derived()
    {
        cout << "Distructor Of Derived " << endl;
        delete i;
    }

private:
    int* i;

};

int main()
{
    // Base* basePtr = new Derived();
    // basePtr->print();
    // delete basePtr;

    /*
        O/P
        Print Of Derived Class 
        Distructor Of Base

        There will be no memory leak as the object initialised of Derived but is of type Base pointer
        So since object is pointing to derived it will call the virtual function from derived but 
        since the distructor is not virtual it will call the distructor which has the type of Base

        Now if we create a constructor in Derived and initialised a pointer veraible and assign a value
        and deleting or releasing it in distructor then after above code execution the distructor of derived is not called
        hence it will be a memory leak for i.

        if we comment the constructor and distructor code for i then there will not be a memory leak
        to fix it mark the destructor of base as virtual
    */

    Derived* derivedPtr = static_cast<Derived*>(new Base());
    derivedPtr->print();
    delete derivedPtr;

    /*
        O/P
        Print Of Base Class 
        Distructor Of Base 

        Here creating object of type base and pointer of Derived class is not allowed a will give compiler error.
        After applying static_cast it allows but then it calls the Print of base class as the object is of base class but when we delete
        the pointer it will call the distructor of Base class because destructor of object is called which is of type base and there is no 
        other parent class above Base hence only that destructor is called

        Now if we mark the destructor of base as non virtual then
    
        O/P
        Print Of Base Class 
        Distructor Of Derived 
        Distructor Of Base 

        Here since the print is virtual hence the print of Base is call based on the type of object but if the print method is not vitual the print of
        Deerived will be called based on type of pointer

        Same is the case with destructor.
    
    
    */

    return 0;
}
