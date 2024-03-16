/*
    1. It will contain unique values
    2. It will be unordered
    3. Internally the elements are stored in the buckets.
    4. It uses hashing to insert elements in to buckets
    5. This allows fast access to individual elements, since once a hash is computed
    it refers to the exact buckets the element is placed in to
*/

#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    std::unordered_set<int> uset ={4, 1, 2, 3, 4, 2, 3};

    auto search = uset.find(2);

    if(search != uset.end())
        cout << "Found " << (*search) << endl;
    else
        cout << "Not Found " << endl;

        
    for(auto& elm: uset)
        std::cout << elm << " ";
    cout << endl;
    return 0;
}
