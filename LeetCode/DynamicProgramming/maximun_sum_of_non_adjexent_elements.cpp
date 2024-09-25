/*
Problem statement
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence 
with the constraint that no two elements are adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the 
array/list, leaving the remaining elements in their original order.

Sample Input 1:
2
3
1 2 4
4
2 1 4 9
Sample Output 1:
5
11

Explanation to Sample Output 1:
In test case 1, the sum of 'ARR[0]' & 'ARR[2]' is 5 which is greater than 'ARR[1]' which is 2 so the answer 
is 5.

In test case 2, the sum of 'ARR[0]' and 'ARR[2]' is 6, the sum of 'ARR[1]' and 'ARR[3]' is 10, and the sum 
of 'ARR[0]' and 'ARR[3]' is 11. So if we take the sum of 'ARR[0]' and 'ARR[3]', it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.

Sample Input 2:
2
5
1 2 3 5 4
9
1 2 3 1 3 5 8 1 9
Sample Output 2:
8
24


*/

#include<iostream>
#include<vector>
using namespace std;

//recursive
int solve(vector<int>& nums, int n)
{
    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0];

    /*
    There is good explanation for this 
    [2 , 1 ,4 , 9] now here we need calculate all the possibility of selection
    like we can select
    2 + 6 = 6
    1 + 9 = 10
    1 + 9 = 11

    hence max is 11

    how to do it is 
    we are astarting from last index i.e n 
    so we will include n - 2 and add it to n since they are not adjcent
    and then we can exclue n - 1 + add 0 

    we keep on doing it till n < 0 or equal to zero recursively so 
    every number and it's adjecent will get chance 

    This is hard for me to understand as I trying to get details in to recursion and DP
    taking time but will get all the forms of options to solve the problems    
    */

    int incl = solve(nums, n - 2) + nums[n];
    int excl = solve( nums, n - 1) + 0;
    
    return max(incl, excl);
}   

//recursive + memoisation
int solveMem(vector<int>& nums, int n, vector<int>& dp)
{
    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0];

    if(dp[n] != -1)
        return dp[n];
    
    /*
    There is good explanation for this 
    [2 , 1 ,4 , 9] now here we need calculate all the possibility of selection
    like we can select
    2 + 6 = 6
    1 + 9 = 10
    1 + 9 = 11

    hence max is 11

    how to do it is 
    we are astarting from last index i.e n 
    so we will include n - 2 and add it to n since they are not adjcent
    and then we can exclue n - 1 + add 0 

    we keep on doing it till n < 0 or equal to zero recursively so 
    every number and it's adjecent will get chance 

    This is hard for me to understand as I trying to get details in to recursion and DP
    taking time but will get all the forms of options to solve the problems    
    */

    int incl = solve(nums, n - 2) + nums[n];
    int excl = solve( nums, n - 1) + 0;
    
    dp[n] = max(incl, excl);
    return dp[n];
} 

int maximumNonAdjacentSum(vector<int> &nums){
    //recrusion
    // int n = nums.size();
    // int ans = solve(nums, n - 1);
    // return ans;

    //recursion + memosation
    // int n = nums.size();
    // vector<int> dp(n , -1);
    // int ans = solveMem(nums, n - 1, dp);
    // return ans;

    //Tabulation
    // int n = nums.size();
    // vector<int> dp(n , 0);

    // dp[0] = nums[0];

    // for(int i = 1; i <= n; ++i)
    // {
    //     int incl = dp[i - 2] + nums[i];
    //     int excl = dp[i - 1] + 0;
    //     dp[i] = max(incl, excl);
    // }

    // return dp[n - 1];

    //Space Optimisation
    int n = nums.size();
    
    int prev2 = 0;
    int prev1 = nums[0];

    for(int i = 1; i < n; ++i)
    {
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}




















