#include<iostream>
using namespace std;

bool check(string& str, int i, int j)
{
    if(i > j)
        return true;
    if(str[i] != str[j])
        return false;
    else
        return check(str, i + 1, j - 1);
}

int main()
{
    string str = "ICICI";
    cout << endl;
    bool isPalindrome = check(str, 0, str.length() - 1);
    if(isPalindrome)
        cout << "It's palindrome" << endl;
    else
        cout << "It's not" << endl;
    return 0;
}