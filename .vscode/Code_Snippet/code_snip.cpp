#include<iostream>
using namespace std;

/*
//Snip 1
class IndiaBix
{
    public: 
    int x, y;
    IndiaBix(int xx = 10, int yy = 20)
    {
        x = xx;
        y = yy; 
    }
    void Exchange(int *, int *);
};
int main()
{
    IndiaBix objA(30, 40); 
    IndiaBix objB(50); 
    objA.Exchange(&objA.x, &objB.y); 
    cout<< objA.x << " " << objB.y << endl; 
    return 0;
}
void IndiaBix::Exchange(int *x, int *y)
{
    int t;
    t  = *x;
    *x = *y;
    *y = t ; 
}

// Output : 20 30
// Explaination: 
// 1. objA x and y is initialised with 30 and 40 ignoring default value
// 2. objB x initialised with 50 and y is not provided hence it will be initialised with 20
// 3. Now exchange is called for objA.x and objB.y hence 30 and 20 will be exchange to raise value as
// 20 30



//Snip  2

#include<iostream>
using namespace std;

class IndiabixSample
{
    private:
    int AdditionOne(int x, int y = 1) 
    {
        return x * y;
    }
     
    public:
    int AdditionTwo(int x, int y = 1)
    {
        return x / y;
    } 
}; 
int main()
{
    IndiabixSample objBix;
    cout<<objBix.AdditionOne(4, 8)<<" "; 
    cout<<objBix.AdditionTwo(8, 8); 
    return 0;
}
 
// Output: Compilation Error
// Explaination:  IndiabixSample::AdditionOne is a private method and is not accessible outside class 


 

//Snip 3
#include<iostream>
using namespace std;

class IndiaBix
{
    int x, y; 
    public:
    IndiaBix(int &xx, int &yy)
    {
        x = xx;
        y = yy;
        Display();
    }
    void Display()
    {
        cout<< x << " " << y;
    }
};
int main()
{
    int x1 = 10; 
    int &p = x1;
    int y1 = 20; 
    int &q = y1; 
    IndiaBix objBix(p, q); 
    return 0; 
}

// Output: 10 20
// Explaination: As when we declare variable as & it becomes alias of that variable
// e.g int x1 = 10 
//     int &p = x1 menas p is alternate name to x1 so of p is changed the value will be change for x1




//Snip 4
#include<iostream>
using namespace std;

int main()
{
    int x = 0;
    int &y = x; y = 5; 
    cout << "x = " << x << endl;
    while(x <= 5)
    {
        cout<< y++ << " ";
        cout << "X = " << x << endl;
        x++;
    }
    cout<< x; 
    return 0; 
}

// Output: 5 7
// // Explaination: 
// 1. x is initially 0
// 2. &y = x so y is alias to x so if y changes it will also change the value of xor
// 3. y = 5 means x also becomes 5 now both x and y are at 5
// 5. in while loop x <=5 both are at 5 hence goes is_unsigned
// 6. now y++ which makes it 6 and since y is alias x also becomes 6 
// 7. now x++ so x becomes 7



//Snip 5
#include<iostream>
using namespace std;

int BixFunction(int m)
{
    cout << "m = "<< m << endl;
    m *= m;
    return((10)*(m /= m)); 
}
int main()
{
    int c = 9, *d = &c, e;
    int &z = e;
    //cout << "c-- % 3 = " << c-- % 3 << endl;
    e = BixFunction(c-- % 3 ? ++*d :(*d *= *d));
    z = z + e / 10;
    cout<< c << " " << e;
    return 0;
}

// Output: 64 11
// Explaination:
// 1. c-- % 3 is zero as c is 9 is not decremented yet but when it reaches else statemement it becomes 8 and 
//     multiply *d with *d which is pointer to c hence becomes 64
// 2. from function it becomes 64*64 and then return 10*(m /=m) which is 10 * 1
// 3. After returning Z + e /10  e is 10 and Z is alias to e hence 10  + 1 as division takes priority 
// 4. c becomes 64 as the value at address changed to 64 and e becomes 11



//Snip 6
#include<iostream>
#include<process.h>
using namespace std;

class IndiaBix
{
    static int x; 
    public:
    IndiaBix()
    {
        if(x == 1)
            exit(0); 
        else
            x++;
    }
    void Display()
    {
        cout<< x << " ";
    }
};
int IndiaBix::x = 0; 
int main()
{
    IndiaBix objBix1; 
    objBix1.Display(); 
    IndiaBix objBix2; 
    objBix2.Display(); 
    return 0; 
}

// Output: 1 and then exit 
// Explaination: 
// 1.When first object is created the constructor is called since x is static and x != 1 hence x increases to 1
// 2. Next time the constructor is called but since x == 1 it exits
*/

//Snip 7
#include<iostream>
#include<string.h> 
class IndiaBix
{
    public:
    void GetData(char *s, int x, int y )
    {
        int i = 0;
        for (i = x-1; y>0; i++)
        {
            cout<< s[i];
            y--; 
        } 
    }
}; 
int main()
{
    IndiaBix objBix;
    objBix.GetData((char*)"Welcome!", 1, 3);
    return 0; 
}

// Output: Wel
// // Explaination:
// 1. Loop will start at 0 as x - 1 x = 1 and till 3 letters as y --
// 2. Hence Wel