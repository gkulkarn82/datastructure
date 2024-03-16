/*
Digit Seperator:
Prior to C++ 14 there is no way to define something like 1,00,000
1. Now there is a better code redability with digit seperator
2. We use sing le quote (') as digit seperator 1'00'000 to represent this number
3. There is no rule of using single quotation mark sing for DS

*/

#include<iostream>
using namespace std;

int main()
{
    auto x = 1'00'000;
    cout << x << endl;
    cin.get();
    return 0;
}