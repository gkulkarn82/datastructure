/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the 
cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor. 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {

// private:
//     int solve(vector<int>& cost, int n)
//     {
//         if(n == 0)
//             return cost[0];
//         if(n == 1)
//             return cost[1];

//         int ans = cost[n] + min(solve(cost, n - 1), solve(cost, n- 2));
//         return ans;
//     }
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size(); 

//         int ans = min(solve(cost, n - 1), solve(cost, n- 2));
//         return ans;
//     }

// private:
//     /*
//         Memoisation approach Top Down
//     */
//     int solve(vector<int>& cost, int n, vector<int>& dp)
//     {
//         if(n == 0)
//             return cost[0];
//         if(n == 1)
//             return cost[1];

//         if(dp[n] != -1)
//             return dp[n];

//         dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n- 2, dp));
//         return dp[n];
//     }
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size(); 
//         vector<int> dp(n + 1, -1);
//         int ans = min(solve(cost, n - 1, dp), solve(cost, n- 2, dp));
//         return ans;
//     }


/*
    Tabulation Approach Bottom Up
*/
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size(); 
//         vector<int> dp(n + 1);

//         dp[0] = cost[0];
//         dp[1] = cost[1];

//         for(int i = 2; i < n; i++)
//         {
//             dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
//         }
//         return min(dp[n - 1], dp[n -2]);
//     }


/*
    Solution 4 with space 
*/
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); 
        //vector<int> dp(n + 1);

        int prev2 = cost[0];
        int prev1 = cost[1];
        int curr = 0;

        for(int i = 2; i < n; i++)
        {
           curr  = cost[i] + min(prev2, prev1);
           prev2 = prev1;
           prev1 = curr;
        }
        return min(prev1, prev2);
    }
};
