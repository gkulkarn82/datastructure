#include<iostream>
using namespace std;

/*
 Sum of 100 natural numbers
*/

int SumNaturals(int n)
{
	if(n == 0)
		return 0;
		
	return SumNaturals(n-1) + n;
}

int main()
{
    cout << SumNaturals(3) << endl;
    return 0;
}

/*
n = 3

int SumNaturals(3)
{
	if(n == 0)
		return 0;
		
	return SumNaturals(2) + 3; 3+ 3 = 6
}


int SumNaturals(2)
{
	if(n == 0)
		return 0;
		
	return SumNaturals(1) + 2; // 1 + 2 = 3
}

int SumNaturals(1)
{
	if(n == 0)
		return 0;
		
	return SumNaturals(0) + 1;// 0 + 1 = 1
}

int SumNaturals(0)
{
	if(n == 0)
		return 0;				== 0
		
	return SumNaturals(2) + 3;
}
*/