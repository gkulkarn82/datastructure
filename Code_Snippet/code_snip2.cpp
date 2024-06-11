#include<iostream>
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

*/

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
