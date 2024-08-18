#include<iostream>
using namespace std;

int powerOf(int n)
{
    if(n == 0)
        return 1;

    return 2 * powerOf(n - 1);
}

int main()
{
    int n;
    cin >> n;

    int ans = powerOf(n);
    cout << ans << endl;
    return 0;
}