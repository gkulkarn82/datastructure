#include<iostream>
using namespace std;

void merge(int arr[], int start, int end)
{
    int mid = (start + end) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int first[len1];
    int second[len2];

    int mainArrayIndex = start;
    for(int i = 0; i < len1; ++i)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; ++i)
    {
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while(index1 < len1 && index2 < len2)
    {
        if(first[index1] < second[index2])
            arr[mainArrayIndex++] = first[index1++];
        else
            arr[mainArrayIndex++] = second[index2++];
    }

    while(index1 < len1)
        arr[mainArrayIndex++] = first[index1++];
    while(index2 < len2)
        arr[mainArrayIndex++] = second[index2++];
}

void mergeSort(int arr[], int start, int end)
{
    if(start >= end)
        return;

    int mid = (start + end) /2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);
}

int main()
{
    int arr[5] = {2,5,1, 6, 9};
    int n = 5;
    mergeSort(arr, 0, n - 1);

    for(int i = 0 ; i < n; ++i)
    {
        cout << " " << arr[i] ;
    }
    cout <<endl;
    return  0;
}