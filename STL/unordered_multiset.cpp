/*

    1. maintains a collection of non-unique items with fast insertion and removal
    2. it stores value in buckets
    3. it decide the bucket after calculating the hash using function.
    4. It allows fast access to the individual element as after calculating hash it knows exactly which 
    bucket to insert 


*/

#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    unordered_multiset<int> umset = {4,1,2,3,9,4,3,2,9,8,10};
    auto search = umset.find(2);
    if(search != umset.end())
        cout << "Found " << (*search) << endl;
    else
        cout << "Not Found" << endl;

    for(auto& elm: umset)
    {
        cout << elm << " ";
    }
    cout << endl;
    cout << umset.count(4) << endl;
    return 0;  
 }