#include<iostream>
using namespace std;

/*
	Factorial using recursion
*/

int factorial(int n)
{
	if(n == 0 || n == 1)
		return 1;
	return  factorial(n - 1) * n;
}

int main()
{
    cout<< factorial(5) << endl;
    return 0;
}

/*
int factorial(int 3)
{
	if(n == 0 || n == 1)
		return 1;
	return  factorial(2) * 3; // 6
}

int factorial(int 2)
{
	if(n == 0 || n == 1)
		return 1;
	return  factorial(1) * 2; // 2
}

int factorial(int 1)
{
	if(n == 0 || n == 1)
		return 1;           => 1  
	return  factorial(0) * 1;
}
*/