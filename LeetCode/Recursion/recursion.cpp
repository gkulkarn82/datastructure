#include<iostream>
using namespace std;

int Func(int m)
{
	static int x = 0;
	if(m > 0)
	{
		++x;
		return Func(m-1) + x;
	}
	return 0;
}

int main()
{
	std::cout<<Func(3)<<std::endl;
	return 0;
}

//output : 9

/*
void Func(3)
{
	static x = 0;               // x  = 0
	if(m > 0)
	{
		++x;                    // x = 1
		return Func(m-1) + x;   // Func(2) + 1; => 9
	}
	return 0;
}

void Func(2)
{
	static x = 0;               // x  = 0
	if(m > 0)
	{
		++x;                    // x = 2
		return Func(m-1) + x;   // Func(1) + 2  => 6
	}
	return 0;
}

void Func(1)
{
	static x = 0;               // x  = 0
	if(m > 0)
	{
		++x;                    // x = 3
		return Func(m-1) + x;   // Func(0) + 3  => 3
	}
	return 0;
}

void Func(0)
{
	static x = 0;               // x  = 0
	if(m > 0)
	{
		++x;                    // x = 1
		return Func(m-1) + x;   // Func(0) + 1
	}
	return 0;
}
*/