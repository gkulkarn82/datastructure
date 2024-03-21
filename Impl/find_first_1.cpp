#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int key)
{
    if(end >= start)
    {
        int mid = start + (end - start )/2;
        if(arr[mid] == key)
            return mid;

        if(arr[mid] > key)
            return binarySearch(arr, start, mid - 1, key);
        else
            return binarySearch(arr, mid + 1, end, key);
    }
    return -1;
}

int posOfFirstOne(int arr[], int key)
{
    int start = 0, end = 1;
    int val = arr[0];
    while(val < key)
    {
        start = end;
        end  = 2 * end;
        val = arr[end];
    }

    return binarySearch(arr, start , end, key);
}
int main()
{
    int arr[] = { 0, 0, 1, 1, 1, 1 };
    cout << "Index = "
         << posOfFirstOne(arr, 1);
    return 0;
}