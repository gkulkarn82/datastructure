#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void solve(string digits, string output, int index, vector<string>& ans, string mappings[])
    {
        if(index >= digits.length())
        {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mappings[number];

        for(int i = 0 ; i < value.length(); ++i)
        {
            output.push_back(value[i]);
            solve(digits, output, index + 1, ans, mappings);
            output.pop_back(); 
        }

    }
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }

};