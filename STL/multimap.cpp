/*
    1. multimap<T1, T2>
    2. is an associative container  which stores a sorted list
    3. can have multiple value to single key
    4. Red black tree is assumed data structure
    5. at and [] are not supported as single key has multiple values associated.

*/

#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    multimap<char, int> Multimap;
    Multimap.insert(make_pair('a', 1));
    Multimap.insert(make_pair('a', 2));
    Multimap.insert(make_pair('a', 3));
    Multimap.insert(make_pair('b', 4));
    Multimap.insert(make_pair('b', 5));

    for(auto& ml: Multimap)
        cout << ml.first << " " << ml.second << endl;


    cout << "=====================================" << endl;
    auto range = Multimap.equal_range('a');
    for(auto it = range.first; it!= range.second; ++it)
        cout<< it->first << " " <<it->second << endl;
    return 0;
}