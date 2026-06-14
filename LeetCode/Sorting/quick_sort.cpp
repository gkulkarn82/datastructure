/*
    Reference : https://www.youtube.com/watch?v=Dl6HT-NM_q4
*/
#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int l, int r)
{
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i =  l - 1;

    for(int j = l; j < r; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, r);
    return i + 1;
     
}
void quicksort(int arr[], int l, int r)
{
    if(l < r)
    {
        int pi = partition(arr, l , r);
        quicksort(arr, l , pi - 1);
        quicksort(arr, pi + 1, r); 
    }

}

int main()
{
    int arr[] = { 3, 2, 6, 8, 7, 4, 9,11,52,100};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0 , n - 1);
    
    for(int i= 0; i < n; i++)
    {
        cout << arr[i] <<  " ";
    }
    cout << endl;
    

    cin.get();
    return 0;
}