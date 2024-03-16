/*
    1. Syntax map<T1, T2> key value
    2. is an associative container which stores value in key & value combination
    3. stores object in an key sorted manner
    4. key is unique
    5. Implemented using AVL or Red Black Tree and is a self balanced tree
*/

#include<iostream>
#include<map>
#include<functional>
#include<vector>
using namespace std;

int main()
{
    std::map<string, int> Map;
    Map["Chotu"] = 123213;
    Map["Amit"] = 654564;
    Map["Amit"] = 6511;
    Map.insert(std::make_pair("Bot", 8787878787));

    for(auto& mp: Map)
        cout << mp.first << " " << mp.second << endl;
}