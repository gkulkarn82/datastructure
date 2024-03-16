/*
    1. multiset can have duplicate objects
    2. it is implemented using red black tree
    3. insertion , deletion and searching have logn complexity
    4. for user defined data types we need to implement comparator function
    5. we can pass order of sorting whule constructing set objects
    6. contains sorted set of diplicate objects

*/

#include<iostream>
#include<set>
#include<string>
#include<functional>
using namespace std;

class Person
{
public:
    int age;
    string name;
    bool operator < (const Person& rhs) const { return age < rhs.age;}
    bool operator > (const Person& rhs) const { return age > rhs.age;}
};

int main()
{
    //multiset<int,  greater<int>> multiset = {5,2,4,3,2,5};
    //multiset.insert(20);

    multiset<Person, greater<>> multiset = {{25, "Rupesh"}, {20, "Hitesh"}};
    for(auto& s: multiset)
        cout << s.age << " " << s.name << endl;
    return 0;
}
