/*
Deprecated Attribute
C++14 introduces the [[deprecated]] attribute to indicate that a unit (function, class, etc.) is discouraged and likely 
yield compilation warnings. If a reason is provided, it will be included in the warnings.

[[deprecated]]
void old_method();
[[deprecated("Use new_method instead")]]
void legacy_method();

*/

#include<iostream>
using namespace std;

[[deprecated ("We will be adding new function based on template class in newer version")]]
int add(int x, int y) { return x * y;}

int main()
{
    cout << add(1,2) << endl;
    cin.get();
    return 0;
}