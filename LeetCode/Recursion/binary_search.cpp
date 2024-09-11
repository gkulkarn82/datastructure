#include<iostream>
using namespace std;

bool binarySearch(int arr[], int start, int end, int key)
{
    if(start > end)
        return false;

    // start + (end - start) the reason is there is possiblity that there is a large array
    // where start + end will lead to the value which is greter than int max which will lead
    // to int overflow which will lead to negative value hence this is needed
    int mid = start + (end - start) / 2 ;

    if(arr[mid] == key)
        return true;
    if(arr[mid] < key)
        return binarySearch(arr, mid + 1, end, key);
    else
        return binarySearch(arr, start , mid - 1, key);
}

int main()
{
    int arr[] = {1,2,4,6,9,8,3,15,24};
    int size = sizeof(arr)/ sizeof(arr[0]);
    int key = 15;
    cout << boolalpha << binarySearch(arr, 0 , size , key);

}