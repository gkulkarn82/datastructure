/*
    1. List is a sequence cotainer that allow non contigious memory allocation
    2. list is internally a doubly linked list
    3. it is faster compared to vector, forward_list (singly linked list), deque provided we have the iterator


*/


#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

int main()
{
    list<int> list1 = {5, 2, 4, 10, 0};
    list<int> list2 = {7, 6, 1, 9};
    
    list1.sort();
    list2.sort();

    //list1.merge(list2);
    
    unordered_map<int, list<int>::iterator> umap;
    
    umap[1] = list2.begin();
   // cout << "umap value of 1 =  " << umap[1] << endl;

    list1.splice(list1.begin(), list1, umap[1]);

    //list1 = list2;

    for(auto& ele: list1)
        cout<< ele << " ";
    cout << endl;

    for(auto& ele: list2)
        cout<<  ele << " ";
    cout << endl;


    
}