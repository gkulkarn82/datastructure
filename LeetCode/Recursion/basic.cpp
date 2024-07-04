#include<iostream>
using namespace std;

int Func(int m)
{
	if(m > 0)
	{		
		return Func(m-1) + m;
	}
	return 0;
}

int main()
{
	std::cout<<Func(3)<<std::endl;
	return 0;
}

/*
void Func(3)
{
	if(m > 0)
	{		
		return Func(m-1) + m; // Func(2) + 3  =>6
	}
}

void Func(2)
{
	if(m > 0)
	{		
		return Func(m-1) + m; // Func(1) + 2 => 3
	}
}

void Func(1)
{
	if(m > 0)
	{		
		return Func(m-1) + m; // Func(0) + 1 => 1
	}
}

void Func(0)
{
	if(m > 0)
	{		
		return Func(m-1) + m; // Func(0) + 1
	}
}

*/