#include<iostream>
#include<string>
using namespace std;

void sayDigit(string arr[], int n)
{
    if(n == 0)
        return;

    //cout << "number = " << n << endl;
    int digit = n % 10;
    //cout << "digit " << digit << endl;
    n = n / 10;    
    sayDigit(arr, n);
    cout << arr[digit] << "  ";
}

int main()
{
    int n;
    cin >> n;
    cout << endl;
    string arr[10] = {"Zero","One", "Two", "Three", "Four", "Five",
                    "Six", "Seven", "Eight", "Nine"};
    sayDigit(arr, n);
    return 0;
}