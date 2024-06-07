#include<iostream>
#include<string>
#include <string.h>
using namespace std;

//Snip 1
/*
main() { 

   int i = 1, j = 2, k = 3, r; 

   r = (i, j, k);

   cout<<r<<endl;
}

// Output: 3
// Explaination:
// A comma operator in C++ is a binary operator. It evaluates the first operand & discards the result, 
// evaluates the second operand & returns the value as a result. It has the lowest precedence among all 
// C++ Operators. It is left-associative & acts as a sequence point.


//Snip 2
main() {
   cout<<strcmp("strcmp()","strcmp()");
}
// Output: 0
// Explaination: It will compare and since both are same it will return 0


//Snip 3
main() { 
   class student { 
      int rno = 10;
   } v;
  
   cout<<v.rno;
}

// Output: Compiler error
// Explaination: rno is private member so is not accessible



//Snip 4
main() { 
   char s[] = "Hello\0Hi";
   
   cout<<strlen(s)<<" "<<sizeof(s);
}

// Output: 5 9
// Explaination:
// 1. since there is \0 hence strlen will calculate till \0 which is 5
// 2. sizeof will get the entire size 


//Snip 5
class Base {
public:
   void f() { 
      cout<<"Base\n";
   }
};
class Derived:public Base {
public: 
   void f() {
      cout<<"Derived\n";
   };
};
main() { 
   Derived obj; 
   obj.Base::f();
}

// Output: Base
// Explaination:
// 1. obj is calling the f() from Base via accesing using Base::

//Snip 6
class BixArray
{
    int Matrix[3][3]; 
    public:
    BixArray()
    {
        for(int i = 0; i<3; i++)
           for(int j = 0; j < 3; j++) 
              Matrix[j][i] = i + j; 
    }
    void Display(void)
    {
        for(int i = 0; i < 3; i++)
           for(int j = 0; j < 3; j++) 
              cout<< Matrix[j][i] << " "; 
    } 
}; 
int main()
{
    BixArray objBix;
    objBix.Display();
    return 0; 
}

// Output: 0 1 2 1 2 3 2 3 4 
// Explaination:


//Snip 7
class IndiaBix
{
    int K; 
    public:
    void BixFunction(float, int , char);
    void BixFunction(float, char, char);
    
};
int main()
{
    IndiaBix objIB;
    objIB.BixFunction(15.09, 'A', char('A' + 'A'));
    return 0;
}
void IndiaBix::BixFunction(float, char y, char z)
{
    K = int(z);
    cout << "k z = " << K << endl;
    K = int(y);
    cout << "k = " << K << endl;
    cout << "y = " << y << " z = " << z << endl;
    K = y + z;
    cout<< "K = " << K << endl; 
}

// Output: -61
// Explaination:
// 1. Character range is 127 so when we have char('A' + 'A') it becomes 130 hence goes in to negative -126
// 2. Now = y + z means 61 + (-126) leads to -61


//Snip 8
class Addition
{
    int x; 
    public: 
    Addition()
    {
        x = 0;
    }       
    Addition(int xx)
    {
        x = xx;
    }
    Addition operator + (int xx = 0)
    {
        Addition objTemp; 
        objTemp.x = x + xx; 
        return(objTemp);
    }
    void Display(void)
    {
        cout<< x << endl;
    }
};

int main()
{
    Addition objA(15), objB;
    objB = objA + 5;
    objB.Display();
    return 0; 
}

// Output: Compiler Error 
// Explaination: Addition operator cannot have default argument



//Snip 9
class Base
{
    public:
    char S, A, M; 
    Base(char x, char y)
    {
        S = y - y;
        A = x + x; 
        M = x * x;
    }
    Base(char, char y = 'A', char z = 'B')
    {
        cout << "got call in 3 parameter constructor" << endl;
        S = y;
        A = y + 1 - 1; 
        M = z - 1;
    }
    void Display(void)
    {
        cout << "got a call in base display" << endl;
        cout<< S << " " << A << " " << M << endl;
    }
};
class Derived : public Base
{
    char x, y, z; 
    public:
    Derived(char xx = 65, char yy = 66, char zz = 65): Base(x)
    {
        x = xx; 
        y = yy;
        z = zz;
        cout << x << " " <<  y << " " << z << endl;
    }
    void Display(int n)
    {
        if(n)
        {
            cout << "got a call here " << endl;
            Base::Display(); 
        }
        else
            cout<< x << " " << y << " " << z << endl; 
    }
};
int main()
{
    Derived objDev; 
    objDev.Display(0-1); 
    return 0;
}

// Output: A A A
// Explaination:
// 1. derived object is creted means derived constructor with default value is called setting 
// x = 65 , y = 66, z = 65 which is A B C
// 2.Then derived Display function is called sending 0 - 1 value which is -1
// 3. Constructor has code if n then call Base::Display since value is non zero it will execute Base
// 4. But prior to that when we call the derived constructor it will also send x value 65 to base initialising
// base constructor with default parameters  Base(char, char y = 'A', char z = 'B')
// where 

//     S = y ; == 65
//     A = y + 1 - 1;  == 65 + 1 - 1 = 65
//     M = z - 1; 66 - 1 = 65

//     hence A A A


//Snip 10
class BixBase
{
    int x;
    public:
    BixBase(int xx = 0)
    {
        x = xx; 
    }
    void Display()
    {
        cout<< x ;
    }
};
class BixDerived : public BixBase
{
    int y; 
    public:
    BixDerived(int yy = 0)
    {
        y = yy;
    }
    void Display()
    {
        cout<< y ;
    }
};
int main()
{
    BixBase objBase(10); 
    BixBase &objRef = objBase;

    BixDerived objDev(20); 
    objRef = objDev;

    objDev.Display(); 
    return 0; 
}

// Output: 20
// Explaination: y has value 20 hence displays the same

*/

//Snip 11
class BixTest
{
    public:
    BixTest(int &x, int &y)
    {
        x++;
        y++;
    } 
};
int main()
{
    int a = 10, b = 20;
    BixTest objBT(a, b); 
    cout<< a << " " << b; 
    return 0; 
}

// Output: 11 21
// Explaination:
// 1. Though a and b are passed as value but captured as alias &x and &y 
// 2. so if the alias changes the value the orginal value will also change