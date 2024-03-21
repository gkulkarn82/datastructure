#include<bits/stdc++.h>
using namespace std;

int main()
{
    /*
    int num;
    int *pi = &num;
    printf("Value of pi: %p\n", pi);

    //here we need to understand tha pi is a int pointer which is cast to void pointer
    void* pv = pi;

    //here we are casting the value of void pointer to int pointer which will be stored in pi
    //here pi will still hold the address of num
    pi = (int*) pv;
    printf("Value of pi: %p\n", pi);

    size_t size = sizeof(void*); // Legal
    //size_t size1 = sizeof(void); // Illegal

    size_t sizet = -5; 
    printf("%d\n",sizet); // while executing this the variable is considered as singed int due to %d hence the high value order 
    //bit is set to 1 to show it negative
    printf("Value is %zu\n",sizet); //here the high value bit is highest power of 2 hence returns large number

    /*
        Here the positive number is treated and printed as is
        since size_t is unsigned
    */
   /* size_t sizet1 = 5; 
    printf("%d\n",sizet1); // while executing this the variable is considered as singed int due to %d hence the high value order 
    //bit is set to 1 to show it negative
    printf("Value is %zu\n",sizet1); //here the high value bit is highest power of 2 hence returns large number

    int i = 10;
    int* j = &i;
    j++;


    int vector[] = {28, 41, 7};
    int *pi = vector; // pi: 100

    printf("%d\n",*pi); // Displays 28
    pi += 1; // pi: 104
    printf("%d\n",*pi); // Displays 41
    pi += 1; // pi: 108
    printf("%d\n",*pi); // Displays 7

    short s;
    short *ps = &s;
    char c;
    char *pc = &c;

    printf("Content of ps before: %d\n",ps);
    ps = ps + 1;
    printf("Content of ps after: %d\n",ps);
    printf("Content of pc before: %d\n",pc);
    pc = pc + 1;
    printf("Content of pc after: %d\n",pc);


    int num = 5;
    void *pv = &num;
    printf("%p\n",pv);
    pv = pv+1; //Syntax warning


    int vector[] = {28, 41, 7};
    int *pi = vector + 2; // pi: 108

    printf("%d\n",*pi); // Displays 7
    pi--; // pi: 104
    printf("%d\n",*pi); // Displays 41
    pi--; // pi: 100
    printf("%d\n",*pi); // Displays 28

    */

    int vector[] = {28, 41, 7};
    int *p0 = vector;
    int *p1 = vector+1;
    int *p2 = vector+2;

    printf("p2-p0: %d\n",p2-p0); // p2-p0: 2
    printf("p2-p1: %d\n",p2-p1); // p2-p1: 1
    printf("p0-p1: %d\n",p0-p1); // p0-p1: -1

    printf("*p0-*p1: %d\n",*p0-*p1); // *p0-*p1: -13

    printf("p2>p0: %d\n",p2>p0); // p2>p0: 1
    printf("p2<p0: %d\n",p2<p0); // p2<p0: 0
    printf("p0>p1: %d\n",p0>p1); // p0>p1: 0


    /*
        This is an example of pointer pointing to constant int
        which is pointer to constant

        To avoid confusion and remember it properly always read these expression from right to left
        here *pci is a pointer which points to int which is constant the value of int cannot be change
        but the pointer can refer to another address
    */

    int num = 5;
    const int limit = 500;
    int *pi; // Pointer to an integer
    const int *pci; // Pointer to a constant integer
    pi = &num;
    pci = &limit;

    /*
        This is an example of const pointer which means once assigned now it can not refere to any other variable
        currently it is pointing to nums address but now we can not change it to refer to other variable

        one more thing it can point to non-const int or vairable only
        here the const keyword is used after * means it will point to constant variable
    */
    int num;
    int *const cpi = &num;

    /*
        Now why abpve code cannot point to const 
        Basic is when the pointer is of type const ptr it means it cannot chnage the address it is pointing to but 
        it can change the value but if the value is type of constant it should not change it
    */

    const int num1 = 100;
    int *const pci1 =&num ; // this pointer cannot change the address it points to but can change it's value
        // but here the num1 is const it's value cannot be change
    /*
        There will be warning for such situation
        warning: initialization discards qualifiers from pointer target type   
    */

    int num;
    int age;
    int *const cpi = &num;
    cpi = &age; // this is not possible as cpi is constant pointer it canot point to anything else than &num

    /*
        This is constant pointer to constant the value and the pointer pointing to both cannot be change
        When the pointer is declared, we must initialize it. If we do not initialize it as shown
        below, we will get a syntax error:
    
    */
    int num;
    const int * const cpci = &limit; 

    //'cpci' : const object must be initialized if not extern

    cosnt int test = 500;
    const int *const test1 =&test;
    const int *const test2 = &test;

    printf("%d\n",*test1);
    printf("%d\n", **test2);
    //both of these will print 500 

    return 0;
}