#include<iostream>
using namespace std;

// int main()
// {
//     char arr[20];
//     int i;
//     for(i = 0; i < 20 ; i++)
//     {
//         *(arr + i) = 65 + i;
//     }
//     *(arr + i) = '\0';
//     cout << arr;
//     return 0;
    
// }
// Output : Entire ABCD...
// Explaination: We are executing *(arr + i) which is same as accessing indices in array 


// int main()
// {
//     int a = 5, b = 10, c = 15;
//     int *arr[] = {&a, &b, &c};
//     cout << arr[1];
//     return 0;
// }

// Output: Addrress of 1 element 
// Expalination: arr is two diamentional array and contains reference so we will get reference 
// if we output *arr[1] then we will get value

// int main()
// {
//     char* ptr;
//     char str[] ="abcdefg";
//     ptr = str;
//     ptr += 5;
//     cout << ptr;
//     return 0;   
// }

// Output: fg
// Explaination : pointer made to point to 5 locaiton

// int func(void *ptr);
// int main()
// {
//     char* str ="abcdefghij";
//     func(str);
//     return 0;
// }

// int func(void *ptr)
// {
//     cout << ptr;
//     return 0;
// }

// Output: prints address of string
// Explaination: it is accepting the void* if we try to print *ptr then it will error out

// int main()
// {
//     int i ;
//     char c;
//     void* data;

//     i = 2;
//     c = 'd';
//     data = &i;
//     cout << "The data points to the integer value  = " << data;
//     data = &c;
//     cout << "The data points to the char value  = " << data; 

//     return 0;
// }

// Output: will print both the adress values
// Explaination: As it is void pointer it will print the address till the time it is casted to proper data type


// int main()
// {
//     int n = 5;
//     void* p = &n;
//     int *pi = static_cast<int*>(p);
//     cout << *pi <<endl;
//     return 0;
// }

// Output: 5
// Explaination: Applied static cast to cast it to integer type;

// int main()
// {
//     int a = 5, c;
//     void*p = &a;
//     double b = 3.14;
//     p = &b;
//     c = a + b;
//     cout << c << "\n" << p;
//     return 0;
// }

// Output: 8 and memory address
// Explaination: As a + b a is int and b is double but after adding it is stroed in c which is int hence it will 
// be 8 and p is void* so it will be printed as address 


// int main()
// {
//     int *p;
//     void *vp;

//     if(vp == p)
//         cout << "equal";
//     return 0;
// }

// Output: No output 
// Explaination: As both of them are not same it will not print anything 

// class Polygon
// {
//     protected:
//         int width , height;
//     public:
//         void set_value(int a, int b)
//         {
//             width = a;
//             height = b;
//         }
// };

// class Output1
// {
//     public:
//         void output(int i);
// };

// void Output1::output(int i)
// {
//     cout << i << endl;
// }

// class Rectangle: public Polygon, public Output1
// {
//     public:
//         int area()
//         {
//             return width * height;
//         }
// };

// class Traingle: public Polygon, public Output1
// {
//     public:
//         int area()
//         {
//             return (width * height/2);
//         }
// };

// int main()
// {
//     Rectangle rect;
//     Traingle trgl;
//     rect.set_value(4,5);
//     trgl.set_value(4,5);
//     rect.output(rect.area());
//     trgl.output(trgl.area());
//     return 0;
// }

// Output :20 10
// Explaination: It is multiple inheritance example


struct a
{
    int count;
};

struct b
{
    int* value;
};

struct c: public a, public b
{

};

int main()
{
    c* p = new c;
    p->value = 0;
    cout << "inherited" ;
    return 0;
}