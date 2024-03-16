/*


*/

#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_multimap<int , char> umm = {{5, 'd'}};
    umm.insert({1, 'a'});
    umm.insert(pair<int, char>(2, 'b'));
    umm.insert(make_pair(3,'c'));
    umm.insert(make_pair(3,'c'));

    for(auto& elm: umm)
        cout << elm.first << " " << elm.second << " " << endl;;
    cout << endl;
    return 0;

}