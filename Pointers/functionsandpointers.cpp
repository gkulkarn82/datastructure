#include<bits/stdc++.h>
using namespace std;


void swapWithPointers(int* pnum1, int* pnum2) 
{
    int tmp;
    tmp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 = tmp;
}

void passingAddressOfConstants(const int* num1, int* num2) 
{
    *num2 = *num1;
}

int* allocateArray(int size, int value) 
{
    int* arr = (int*)malloc(size * sizeof(int));
    for(int i=0; i<size; i++) {
    arr[i] = value;
    }
    return arr;
}

int& func(int* i)
{
    *i = 20;
    return *i;
}

int& func1(int& i)
{
    i = 10;
    return i;
}

int* func3(int* i)
{
    *i = 20;
    return i;
}
int main()
{
    // int n1 = 5;
    // int n2 = 10;
    // swapWithPointers(&n1, &n2);


    // const int limit = 100;
    // int result = 5;
    // passingAddressOfConstants(&limit, &result);


    // int* vector = allocateArray(5,45);
    // for(int i=0; i<5; i++) {
    // printf("%d\n", vector[i]);
    // }
    int test = 0;
    int test2 = 0;
    int* test3 = 0;
    cout << func(&test) << endl;
    cout << func1(test2) << endl;
    cout << func3(test3) << endl;



    return 0;
}