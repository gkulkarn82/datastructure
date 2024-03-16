/*

    1.unordered  key value pair but keys are unique
    2.uses bucket to store value using hashing
    3. hence searching , inserting and deletion is  average constant time
    4.



*/

#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<int , char> umap ={{1, 'a'}, {2,'b'}};

    cout << umap[1] <<endl;
    cout << umap[2] <<endl;

    umap[1] = 'c';

    for(auto& elm: umap)
        cout << elm.first << " " << elm.second <<" " ;
    cout << endl;
    return 0;
}