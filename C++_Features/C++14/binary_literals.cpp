/*
Binary Literals
Binary literals provide a convenient way to represent a base-2 number. It is possible to separate digits with  

Prior to c++ 11 there were no binary literals .
To assign binary value or initialise variable with binary value we need to get the hex value and assign
 e.g int x = 0xFF to represent binary value  11111111 which is 255 and need to add comment for better understanding


 with c++ 14 it is possible now we can directy assign binary value
*/

#include<iostream>
using namespace std;

int main()
{
    int b1 = 0xFF; // Binary 11111111 
    cout << b1 << endl;

    int b2 = 0b11111111;
    cout << b2 << endl;

    return 0;
}

