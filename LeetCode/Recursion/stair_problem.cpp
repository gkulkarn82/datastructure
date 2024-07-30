#include<iostream>
using namespace std;

int countDistinctWaysToClimbStair(int nstair)
{
    if(nstair < 0)
        return 0;
    if(nstair == 0)
        return 1;

    return countDistinctWaysToClimbStair(nstair - 1) + countDistinctWaysToClimbStair(nstair - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << endl;

    int ans = countDistinctWaysToClimbStair(n);
    cout << ans << endl;

    return 0;
}