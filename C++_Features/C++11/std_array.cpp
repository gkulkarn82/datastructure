/*
std::array
std::array is a container built on top of a C-style array. Supports common container operations such as sorting.

std::array<int, 3> a = {2, 1, 3};
std::sort(a.begin(), a.end()); // a == { 1, 2, 3 }
for (int& x : a) x *= 2; // a == { 2, 4, 6 }

 => It more safer than normal c style array
 => c++ array is a container or an entity which has #include<array>
 => They created an class of array which is safer
 => we can not do any invalid memory allocation
 => Invalid access of array element it will throw exception and safe your memory
 => its a template hence need to define using array<datatype, size>
*/

#include<iostream>
#include<array>
using namespace std;

int main()
{
    array<int, 10> arr;
    arr[0] = 99;
    arr[1] = 88;
    arr[2] = 77;
    arr.at(3) = 66;

    for(int i = 0 ; i < 4; i++)
        cout << arr[i] << " ";
    cout << endl;

    //range based for loop
    for(auto& i : arr)
        cout << i << " ";
    cout << endl;

    cout << arr.front() << endl;
    cout << arr.back() << endl;
    
    arr.back() = 4;
    for(auto& i : arr)
        cout << i << " ";
    cout << endl;

    cout << arr.size() << endl;
    cout << boolalpha << arr.empty() << endl;

    array<char, 6> arrchar= {'a', 'b', 'c', 'd', 'e', '\0'};
    cout << arrchar.data() << endl;
    cout << arrchar.max_size() << endl;
    arrchar[-1] = 'j';

    cout << arrchar.data() << endl;

    array<char, 6> char_arr {'a', 'b', 'c', 'd', 'e', '\0'};
    for(auto& i: char_arr)
        cout << i << " ";

    char_arr.fill(9);
    cout << "\nAfter fill " << endl;
    for(auto& i: char_arr)
        cout << i << " ";

    cout << endl;

    array<int , 5> arr4 {1,2,3,4,5};
    arr4.fill(9);

    array<int , 5> arr5;
    arr5.fill(8);

    if(arr4 < arr5)
        cout << "arr4 is less " << endl;
    else
        cout << "arr5 is less " << endl;

    cin.get();
    return 0;
}