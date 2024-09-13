#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
    provided string and output the lexiographical string with permutation

    string "abc"
    O/P abc,bac,cab,acb,bca,cba

    nums = [1,2,3]
    O/P

*/

class Solutions
{
private:
    void solve(vector<int> nums, vector<vector<int>>& ans, int index)
    {
        if(index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int j = index; j < nums.size(); ++j)
        {
            //swap here and later revert it
            swap(nums[index], nums[j]);
            solve(nums, ans, index + 1);

            //revert swap here which is called backtracking
            //here we are reverting what we have done at line 28 and get element at original position
            swap(nums[index], nums[j]); 
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans
    }
};