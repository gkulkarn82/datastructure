/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of 
money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have 
security systems connected and it will automatically contact the police if two adjacent houses were broken 
into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of 
money you can rob tonight without alerting the police.


Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


*/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    // int rob(vector<int>& nums) {
    //     // int n = nums.size();
    //     // if(n == 0) return 0;
    //     // if(n == 1) return nums[0];
    //     // int val1 = nums[0], val2 = max(val1, nums[1]);

    //     // for(int i = 2; i < n ; ++i)
    //     // {
    //     //     int temp = val2;
    //     //     val2 = max(val2, val1 + nums[i]);
    //     //     val1 = temp;

    //     // }
    //     // return val2;

    //     int rob = 0, norob = 0;
    //     for(int i = 0 ; i < nums.size(); ++i)
    //     {
    //         int newRob = norob + nums[i];
    //         int newnoRob = max(norob, rob);
    //         rob = newRob;
    //         norob = newnoRob;
    //     }
    //     return max(rob, norob);
    // }

    //recursive
    int solve(vector<int>&nums, int n)
    {
        if(n < 0)
            return 0;
        if(n == 0)
            return nums[0];

        int incl = solve(nums, n - 2) + nums[n];
        int excl = solve(nums, n - 1) + 0;

        return max(incl, excl);
    }

    //recursive + memoisation
    int solve(vector<int>&nums, int n, vector<int>& dp)
    {
        if(n < 0)
            return 0;
        if(n == 0)
            return nums[0];

        if(dp[n] != -1)
            return dp[n];

        int incl = solve(nums, n - 2) + nums[n];
        int excl = solve(nums, n - 1) + 0;

        dp[n] = max(incl, excl);
        return dp[n]
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = solve(nums, n - 1);
        return ans;


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
};





















