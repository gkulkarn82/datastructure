#include<iostream>
#include<string.h>
using namespace std;

/*
//Snip 1
const double BixConstant(const int, const int = 0);
int main()
{
    const int c = 2 ;
    cout<< BixConstant(c, 10)<< " "; 
    cout<< BixConstant(c, 20)<< endl; 
    return 0;
}
const double BixConstant(const int x, const int y)
{
    return( (y + (y * x) * x % y) * 0.2);
}

// Output: 2 4
// Explaination: Based on the operator precedence the output is generated
// 1. for x = 2 and y = 10 
// (y + (y * x) * x % y) * 0.2 = (10 + (2 * 10) * 2 % 10) * 0.2 = (10 + 40 % 10) * 0.2 = 10 * 0.2 = 2
// 2. for x = 2 and y = 20 
// (y + (y * x) * x % y) * 0.2 = (20 + (2 * 20) * 2 % 10) * 0.2 = (10 + 80 % 10) * 0.2 = 20 * 0.2 = 4

//Snip 2
class IndiaBix
{ 
    public:
    void Bix(int x = 15)
    {
        x = x/2; 
        if(x > 0)
            Bix(); 
        else
            cout<< x % 2; 
    } 
};
int main()
{
    IndiaBix objIB;
    objIB.Bix();
    return 0; 
}

// // Output: Program will go into infinite loop
// // Explaination:
// 1. the Bix function has parameter with default value 15 every time this function will be called x = x/2 
// which will always be  x > 0 and it will again call Bix() function with default value so it will be infinite loop


//Snip 3
class AreaFinder
{
    float l, b, h; 
    float result; 
    public:
    AreaFinder(float hh = 0, float ll = 0, float bb = 0) 
    {
        l = ll; 
        b = bb; 
        h = hh;
    }
    void Display(int ll)
    {
        if(l = 0)
            result = 3.14f * h * h; 
        else
            result = l * b; 
        cout<< result; 
    }
};
int main()
{
    AreaFinder objAF(10, 10, 20);
    objAF.Display(0); 
    return 0; 
}
// Output: 0
// Explaination: as if condition is not comparing value it is using assignment operator hence l will be 0
// and since l is zero it will go to else statement where result = l * b means 0 * 20 means 0



//Snip 4
class IndiabixSample
{
    public:
        int   a; 
        float b;
        void BixFunction(int a, float b, float c = 100.0f)
        {
            cout<< a % 20 + c * --b;
        } 
}; 
int main()
{   IndiabixSample objBix;
    objBix.BixFunction(20, 2.000000f, 5.0f);
    return 0; 
}

// Output: 5
// Explaination: default will be replaced by the parameter sent 
// hence A % 20 + c * --b = 20 % 20 + 5.0 * --2 = 0 + 5.0 * 1 = 5


//Snip 5
void Tester(float xx, float yy = 5.0);
class IndiaBix
{
    float x; 
    float y; 
    public:
    void Tester(float xx, float yy = 5.0)
    {
        x = xx;
        y = yy;
        cout<< ++x % --y; 
    }
};
int main()
{
    IndiaBix objBix;
    objBix.Tester(5.0, 5.0);
    return 0; 
}
// Output: Compilation error
// Explaination: We cannot use % for float type variables

//Snip 6
class BixTeam
{
    int x, y; 
    public:
    BixTeam(int xx)
    {
        x = ++xx;
    }
    void Display()
    {
        cout<< --x << " ";
    }
};
int main()
{
    BixTeam objBT(45);
    objBT.Display();
    int *p = (int*)&objBT;
    *p = 23;
    objBT.Display();
    return 0; 
}
// Output : 45 22
// Explaination: 
// 1. ++xx will make it 46 and at display it will reduce by one which is  45
// 2. Now the object objBT is assigned to int pointer and change value to 23 and display the value will change it to --
//  means 22


//Snip 7
class Point
{
    int x, y; 
    public:
    Point(int xx = 10, int yy = 20)
    {
        x = xx;
        y = yy; 
    }
    Point operator + (Point objPoint)
    {
        Point objTmp;
        objTmp.x = objPoint.x + this->x; 
        objTmp.y = objPoint.y + this->y;
        return objTmp;
    }
    void Display(void)
    {
        cout<< x << " " << y;
    }
};
int main()
{
    Point objP1;
    Point objP2(1, 2);
    Point objP3 = objP1 + objP2;
    objP3.Display(); 
    return 0; 
}

// Output:  11 22
// Explaination:
// 1. objp1 will initialised default constructor with detfault value setting x = 10 and y = 20
// 2. then objp2 will set x = 1 and y = 2
// 3. operator overaloading will lead to adding these objects 
// 4. making it 11 and 22



//Snip 8
class Bix
{
    int x, y; 
    public:
    void show(void);
    void main(void);
};
void Bix::show(void)
{ 
    Bix b;
    b.x = 2;
    b.y = 4;
    cout<< x << " " << y;
}
void Bix::main(void)
{
    Bix b;
    b.x = 6; 
    b.y = 8;
    b.show();
}
int main(int argc, char *argv[])
{
    Bix run;
    run.main();
    return 0; 
}
// Output: 6 8
// Explaination:
// 1. Here in main new b object is created and assigned value as  6 and 8
// 2. Now using b.show() function is called so the value of b is still 6 and 8
// 3. in Show again we are creating new object as Bix b and setting the value as 2 and 4 this is new object with value 
// 4. but while printing we are printing x and y which is local so the value will be 6 and 8 from the calling 
// method Bix object

//Snip 9
int main()
{
    int x = 80; 
    int &y = x;
    x++;
    cout << x << " " << --y;
    return 0;
}


//Snip 10
enum xyz 
{
    a, b, c
}; 
int main()
{
    int x = a, y = b, z = c; 
    int &p = x, &q = y, &r = z; 
    p = z; 
    p = ++q;
    q = ++p;
    z = ++q + p++; 
    cout<< p << " " << q << " " << z;
    return 0; 
}
// Output: 4 4 7
// Explaination:
// 1.Enums has default value starts from 0 1 2 so a = 0 b = 1 c = 3
// 2. these values are assigned to x , y,z respectively
// 3. p = z  means = 2;
// 4. p = ++q = 2
// 5. q= ++p  means both p and q are at 3  3
// 6. ++q + p++ means q = 4 and p = 3 z = 7 as p is post increament
// 7. output after post increment is 4 4 7



//Snip 11
class IndiaBix
{
    int val; 
    public:
    void SetValue(char *str1, char *str2)
    {
        val = strcspn(str1, str2);
    }
    void ShowValue()
    {
        cout<< val;
    } 
};
int main() 
{
    IndiaBix objBix;
    objBix.SetValue((char*)"India", (char*)"Bix"); 
    objBix.ShowValue(); 
    return 0; 
}

// Output: 3
// Explaination: strcspn is a function which returns the value till bot the string finds matching value 
// 1. here India and Bix are not matching characters hence 3 value

//Snip 12
class IndiaBix
{
    int x; 
    public:
    IndiaBix(short ss)
    {
        cout<< "Short" << endl;
    }
    IndiaBix(int xx)
    {
        cout<< "Int" << endl;
    }
    IndiaBix(float ff)
    {
        cout<< "Float" << endl;
    }
    ~IndiaBix() 
    {
        cout<< "Final";
    }
};
int main()
{
    IndiaBix *ptr = new IndiaBix('B');
    return 0; 
}

// Output: int
// Explaination: There are no constructor for char and the nearest matching constructor is the one accepting int
// so Int will be printed

//Snip 13
class BixBase
{   
    public:
    BixBase()
    {
        cout<< "Base OK. "; 
    }
    ~BixBase()
    {
        cout<< "Base DEL. "; 
    }
};
class BixDerived: public BixBase
{
    public:
    BixDerived()
    { 
        cout<< "Derived OK. "; 
    }
    ~BixDerived()
    { 
        cout<< "Derived DEL. "; 
    }
};
int main()
{
    BixBase *basePtr = new BixDerived();
    delete basePtr;
    return 0;
}

// Output:  Base OK. Derived OK. Base DEL. 
// Explaination:
// 1. Pointer is of type Base so base constructor is called
// 2. Pointer is created from Derived so derived constructor is called.
// 3. Since base class do not have virutal destructor so only Base destructor will be called.
*/

//Snip 14
// int main() {
//    auto glambda = [](auto a, auto&& b) { return a < b; };
//    bool b = glambda(3, 3.14);
//    std::cout<<b;
   
//     return 0;
// }

// Output: 1
// Explaination: it will output 1 as we are not using boolalpha to parase it to print True or false


//Snip 15
// class base
// {
// public:
//        base()
//        {          
//            cout<<"BCon";
//        }
//        ~base()
//        {
// 	   cout<<"BDest ";
//        }
// };
// class derived: public base
// {
// public:
//        derived()
//        {     cout<<"DCon ";
//        }
//        ~derived()
//        {     cout<<"DDest ";
//        }
// };

// int main()
// {
// derived object;
// return 0; 
// }

// Output: BCon DCon DDest BDest