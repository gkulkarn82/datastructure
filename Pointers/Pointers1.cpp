#include<bits/stdc++.h>
using namespace std;

float* fun(float*);
int* check(int, int);
int* func(int*);

void swap(int* , int*);
void exchange(int**, int*);
int power(int**);

float* multiply(int , float);

int main()
{

    //Program 1
    // float a = 7.999999;
    // float *b, *c;
    // b = &a;
    // c = b;

    // printf("%u %u %u\n", &a,b,c);

    //here the issues are
    /*
        it should actually print the 7.000 but
        the fact is the format specifier is %d and not %f so that blows the problem

        so the ouput can be anything random 
        we cannot rely on printf to convert float to int by truncating values
    */
    //printf("%d %d %d %d\n", a, *(&a), *b, *c);
    /*
        O/P above code
        875466340 875466340 875466340
        -1872318800 0 1 0 // this is due to %d to print float value
    
    */

    // int i = 10;
    // printf("%f\n", i);

    //*****************************************************

    //Program 2
    // int* ch;
    // ch = check(10,20);
    // printf("c = %u\n", ch);

    //*******************************************************

    //Program 3
    // float p = 23.5, * q;
    // q = &p;
    // printf("q before call = %u \n", q);
    // q = fun(&p);
    // printf("q after call = %u \n", q);

    //*******************************************************

    //Program 4
    // int somenumber, *st;
    // st = &somenumber;
    //  printf("st before call = %u \n", st);
    // st = func(&somenumber);
    // printf("q after call = %u , value = %d\n", st, *st);


    //*******************************************************

    //Program 5
    // int a = 10, *j;
    // void *k;
    // j++;
    // k++;
    // printf("%u %u \n",j, k);

    //*******************************************************

    //Program 6
    // float *p1, i = 25.50;
    // char* ch;
    // p1 = &i;
    // ch = &i;
     
    //*******************************************************

    //Program 7  Compiler error for casting
    // char c, **cc;
    // int i;
    // long l;
    // float f;

    // c= 'z';
    // i = 15;
    // l = 77777;
    // f = 3.14;
    // cc = &c;

    // printf("c = %c cc= %u \n", *cc, c);
    // cc = &i;
    // printf("i = %d cc= %u \n", *cc, c);
    // cc = &l;
    // printf("i = %ld cc= %u \n", *cc, c);
    // cc = &f;
    // printf("i = %f cc= %u \n", *cc, c);
    
    //*******************************************************

    //Program 8  
    // int c = 10, d= 20;
    // printf("Before swap . c = %d d= %d \n",c ,d);
    // swap(&c, &d);
    // printf("After swap . c= %d d= %d \n",c, d);

    //*******************************************************

    //Program 9
    // int a = 5 , *aa;
    // aa = &a;
    // a = power(&aa);
    // printf("a = %d aa = %u\n",a, aa);

    //*******************************************************

    //Program 10
    //local veriable reference is returned so 0 value will be print
    //local value referece will lost once function ends
    // int i = 3;
    // float f= 3.50, *prod;

    // prod = multiply(i,f);
    // printf("prod = %u value at address = %f\n, prod, *prod");

    //*******************************************************

    //Program 11
    //Invalid Conversion
    // char* c = 4000;
    // int * i = 4000;
    // long *l = 4000;
    // float* f= 4000;
    // double*d = 4000;

    // printf("c = %u, c + 1 = %u\n",c, c + 1);
    // printf("i = %u, i + 1 = %u\n",i, i + 1);
    // printf("l = %u, l + 1 = %u\n",l, l + 1);
    // printf("f = %u, f + 1 = %u\n",f, f + 1);
    // printf("d = %u, d + 1 = %u\n",d, d + 1);

    //*******************************************************

    //Program 12
    // int i = 10;
    // printf("value of i = %d address of i = %u\n", i, &i);
    // &i = 7200;
    // printf("new value of i = %d new address of i = %u\n", i, &i);

    int *i, *j;
    j = i * 2;
    printf("j = %u\n", j);

    return 0;
}

/*
float* multiply(int ii, float ff)
{
    float product ;
    product = ii * ff;
    printf("product = %f address of product = %u\n", product , &product);
    return &product;
}

int power(int** ptr)
{
    int b ;
    b = **ptr***ptr;
    return b;
}
void swap(int* cc, int *dd )
{
    //here reference , dd value
    exchange(&cc, dd);
}

void exchange(int **cc, int *dd)
{
    int t ;
    t = **cc;
    **cc = *dd;
    *dd = t;
}

int* func(int* i)
{
    *i = 20;
    return i;
}

float* fun(float* r)
{
    r = r + 1;
    return r;
}

int* check(int i, int j)
{
    int *p, *q;
    p = &i;
    q = &j;

    if(i >= 45)
        return p;
    else
        return q;
}

*/