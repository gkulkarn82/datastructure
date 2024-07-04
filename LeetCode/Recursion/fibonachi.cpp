#include<iostream>
using namespace std;

/*
	Fibonachi Series

*/
//0 1 1 2 3 5 8 13

int Fibo(int n)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
		
	return Fibo(n - 1) + Fibo(n - 2);
}

int main()
{
    cout << Fibo(5) << endl;
    return 0;
}


/*
int Fibo(6)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
		
	Fibo(n - 1) + Fibo(n - 2); // Fibo(5)=> 5 + Fibo(4) => 3; => 8
}

int Fibo(5)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
		
	Fibo(n - 1) + Fibo(n - 2); // Fibo(4)=> 3 + Fibo(3) => 2; => 5
}

int Fibo(4)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
		
	Fibo(n - 1) + Fibo(n - 2); // Fibo(3)=> 2 + Fibo(2) => 1; => 3
}

int Fibo(3)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
		
	Fibo(n - 1) + Fibo(n - 2); // Fibo(2)=> 1 + Fibo(1) => 1; => 2
}

int Fibo(2)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
		
	Fibo(n - 1) + Fibo(n - 2); // Fibo(1)=> 1 + Fibo(0) => 0; => 1
}

int Fibo(1) // Fibo(1)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
		
	Fibo(n - 1) + Fibo(n - 2); // Fibo(1) + Fibo(0);
}

int Fibo(0) // Fibo(0)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
		
	Fibo(n - 1) + Fibo(n - 2); // Fibo(1) + Fibo(0);
}

*/