#include<iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int cnt = 0;

    for(int i = start + 1; i <= end; ++i)
    {
        if(arr[i] <= pivot)
            cnt++;
    }

    int pivotIndex = start + cnt;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;
    while(i <pivotIndex && j >pivotIndex)
    {
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i <pivotIndex && j >pivotIndex )
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    if(start >= end)
        return;

    int p = partition(arr, start, end);
    quickSort(arr, start , p - 1);
    quickSort(arr, p + 1, end);
}

int main()
{
    int arr[] = {1,6,2,8,4,7,10};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size -1);

    for(int i = 0 ; i < size; ++i)
    {
        cout<< " " << arr[i] ;
    }

    cout << endl;

    return 0;
}