#include<iostream>
using namespace std;

void printCount(int n)
{
    if(n == 0)
        return;
    cout << n << endl; // Tail recursion
    printCount(n - 1);
    cout << "Head Recursion "<< endl; // Head Recursion
    cout << n << endl;
}

int main()
{
    int n;
    cin >> n;
    cout << endl;
    printCount(n);
    return 0;
}