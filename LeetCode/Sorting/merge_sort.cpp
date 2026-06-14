/*
    Reference : https://www.youtube.com/watch?v=4z9I6ZmeLOQ

*/
#include<bits/stdc++.h>
using namespace std;


void merge(int arr[], int start, int end)
{
    int mid = (start + end) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid ; 

    int* first = new int[len1];
    int* second = new int[len2];

    int mainArray = start;
    for(int i = 0 ; i < len1; i++)
        first[i] = arr[mainArray++];

    mainArray = mid + 1;
    for(int i = 0; i < len2; i++)
        second[i] = arr[mainArray++];

    
    int index1 = 0;
    int index2 = 0;
    mainArray = start;

    while(index1 < len1 && index2 < len2)
    {
        if(first[index1] < second[index2])
            arr[mainArray++] = first[index1++];
        else
            arr[mainArray++] = second[index2++];
    }

    
    while(index1 < len1)
        arr[mainArray++] = first[index1++]; 

    while(index2 < len2)
        arr[mainArray++] = second[index2++]; 

    delete[] first;
    delete[] second;

}
void mergesort(int arr[], int start, int end)
{
    if(start >= end)
        return;

    int mid = (start + end) / 2;

    mergesort(arr, start, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, start , end);

}
int main()
{
    int arr[5] = {3,9,10 ,1,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n -1);
   
    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << " ";
    cout << endl;
}