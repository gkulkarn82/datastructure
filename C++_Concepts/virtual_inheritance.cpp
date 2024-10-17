/*
    Virtual Inheritance
*/

#include<bits/stdc++.h>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Constructor Of Base " << endl;
    }
    virtual void print()
    {
        cout << "Print Of Base Class " << endl;
    }

    ~Base()
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
        cout << "Constructor Of Deerived " << endl;
        //i = new int(5);
    }

    void print() override 
    {
        cout << "Print Of Derived Class " << endl;
    }

    ~Derived()
    {
        cout << "Distructor Of Derived " << endl;
        //delete i;
    }

private:
    int* i;

};

int main()
{
    // Base* basePtr = new Derived();
    // basePtr->print();
    // delete basePtr;

    //Upcasting is allowed where below code this is a downcasting which is not allowed
    //    Derived* derivedPtr = dynamic_cast<Derived*>(new Base());
    //    if(derivedPtr == nullptr)
    //    {
    //         cout<< "This is null casting failed";
    //         return 0;     
    //    }
    //    derivedPtr->print();
    //    delete derivedPtr;

    /*
        O/P
        Print Of Derived Class 
        Distructor Of Base

        There will be no memory leak as the object initialised of Derived but pointer is of type Base pointer
        So since object is pointing to derived it will call the virtual function from derived but 
        since the distructor is not virtual it will call the distructor which has the type of Base

        Now if we create a constructor in Derived and initialised a pointer varible and assign a value
        and deleting or releasing it in distructor then after above code execution the distructor of 
        derived will not be called hence it will be a memory leak for i.

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

        Here creating object of type base and pointer of Derived class is not allowed and will give compiler error.
        After applying static_cast it allows but then it calls the Print of base class as the object is of base class but 
        when we delete the pointer it will call the distructor of Base class because destructor of object is called which 
        is of type base and there is no other parent class above Base hence only that destructor is called

        Now if we mark the destructor of base as non virtual then
    
        O/P
        Print Of Base Class 
        Distructor Of Derived 
        Distructor Of Base 

        Here since the print is virtual hence the print of Base is call based on the type of object but if the print 
        method is not vitual the print of  Derived will be called based on type of pointer

        Same is the case with destructor.
    */

    // Base* ptr = new Derived();
    // delete ptr;
    return 0;
}


/*
    Detailed Notes :
        As I keep forgetting things hence I decide to have a proper notes which I can read and which will give me the 
        correct pointers when I am going through them

    I : Without Virtualisation
    class Emp
    {
        public:
            void RaiseSalary()
            {
                //some code
            }
    }
    class Engineer: public Emp
    {
        public:
            void RaiseSalary()
            {
                //some code
            }
    }

    int main()
    {
        Emp* emp = new Engineer();
        emp->RaiseSalary(); 
    }
    
    //In this situation the function will be called based on the type of object created i.e Emp and not based on constructor
    //Hence the base class method will be called

    II: With Virtualisation

    class Emp
    {
        public:
            virtual void RaiseSalary()
            {
                //some code
            }
    }
    class Engineer: public Emp
    {
        public:
            void RaiseSalary()
            {
                //some code
            }
    }

    int main()
    {
        Emp* emp = new Engineer();
        emp->RaiseSalary(); 
    }

    // Here the function is virtual hence the function will be called based on the constructor() and not based on type
    //Reason

    1.Every class has a vtable and vptr becase 
        - if any class has at least one virtual method then all it's sucessing classes has vptr and vtable
    2.vtable maintaince the table of function pointer and vptr points to it
    3. Vtables are static arrays
        - i.e All the object instances points to the same vtable

    vtable for Emp
    Emp* obj = new Emp();
    this will create object of type Emp vptr will point to EMP vtable like below

    --------------------------------------------------------------------------------------
    | Sr   | Function Name   | Class      |  Comments                                    |
    --------------------------------------------------------------------------------------
    |  1   | RaiseSalary     | Emp        |  This is virutal function form Emp class     |
    --------------------------------------------------------------------------------------
    |  2   | Promote         | Emp        |  This is non virtual function from emp class |
    --------------------------------------------------------------------------------------

    vtable for Engineer
    Emp* obj = new Engineer();
    obj is object of type Emp and will point at Engineer vtable
    here 
    1. RaiseSalary will be pointed from Enginner class
    2. Promote since it is non- virtual function based inherited hence will point to Emp class

    ----------------------------------------------------------------------------------------------
    | Sr   | Function Name   | Class      |  Comments                                            |
    ----------------------------------------------------------------------------------------------
    |  1   | RaiseSalary     | Engineer   |  This is function form Engineer class                |
    ----------------------------------------------------------------------------------------------
    |  2   | Promote         | Emp        |  This is non virtual but inherited function from Emp |
    ----------------------------------------------------------------------------------------------












*/
