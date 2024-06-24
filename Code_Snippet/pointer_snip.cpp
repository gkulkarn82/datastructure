#include<iostream>
#include<stdio.h>
using  namespace std;

/*
//Snip 1
main()
{
    float a = 10.2;
    int *p = a;
    printf("%d",*p);
}

Output: compilation error not a compatible type
Explaination: Cannot initialised int pointer with float


//Snip 2
main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *p = a;
    printf("%d\t%d\t%d\t%d\t",*p,0[a],a,p);
}

// Output : 1 1 Address address
// Explaination:
// 1.*p and 0[a] will access the value at base address which is 0th location 
// 2.a and p will print the address
*/

// int arr[] = {1,2,3};
// main()
// {
//     int *ptr; 
//     ptr = arr;
//     ptr = ptr + 3;
//     printf("%d",*ptr);
// } 

// Output: 0
// Explaination:

// int main()
// {
//     int const *p = 5;
//     printf("%d", ++(*p));
// }

// Output: Compilation error invalid conversion from int to int*
//Explaination: Cannot modify a constant value. p is a pointer to a constant integer.
// But we tried to change the value of the constant integer


// int main()
// {
//     struct std
//     {
//         int x = 3;
//         char name[] = "hello";
//     };
//     struct std *s;
//     printf("%d", s->x);
//     printf("%s", s->name);
// } 

// Output: hello 5
// Explaination: error because of initializing variables in structure declaration


// int main()
// {
//     register i = 5;
//     char j[] = "hello";
//     printf("%s %d", j, i);
// }

// Output: hello 5
// Explaination: if you declare i as register compiler will treat it as ordinary integer and it will take integer value.
// i value may be stored either in register or in memory



// int fun(int *a,int *b)
// {
//     *a = *a+*b;
//     *b = *a-*b;
//     *a = *a-*b;
// }

// int main()
// {
//     int x = 10,y = 20;
//     fun(&x,&y);
//     printf("x= %d y = %d\n", x, y);
// }

// Output: x = 20 , y = 10