#include<iostream>
using namespace std;

// int fib(int n, int dp[])
// {
//     if(n <= 1)
//         return 1;
//     if(dp[n] != -1)
//         return dp[n];
//     dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
//     return dp[2]; 
// }
int main()
{
    int n = 6;
    int dp[n + 1];
    //fib(n, dp);

    cout << fib(n) << endl;

    return 0; 
}

//Bottom-up Approach
/*
    we can optimised the space here 
*/
int fib(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fib(int n)
{
    int prev1 = 1;
    int prev2 = 0;
    int curr = 0;

    if(n == 0)
        return prev2;
        
    for(int i = 2; i <= n; ++i)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}