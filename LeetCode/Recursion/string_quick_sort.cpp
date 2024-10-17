#include<iostream>
using namespace std;

int partition(std::string& str, int start, int end)
{
    int pivot = str[start];
    int cnt = 0;

    for(int i = start + 1; i <= end; ++i)
    {
        if(str[i] <= pivot)
            cnt++;
    }

    int pivotIndex = start + cnt;
    swap(str[pivotIndex], str[start]);

    int i = start, j = end;
    while(i <pivotIndex && j >pivotIndex)
    {
        while(str[i] < pivot)
            i++;
        while(str[j] > pivot)
            j--;
        if(i <pivotIndex && j >pivotIndex )
            swap(str[i++], str[j--]);
    }
    return pivotIndex;
}

void quickSort(std::string& str, int start, int end)
{
    if(start >= end)
        return;

    int p = partition(str, start, end);
    quickSort(str, start , p - 1);
    quickSort(str, p + 1, end);
}

int main()
{
    std::string str = "zathbmplocd";
    quickSort(str, 0, str.size() -1);

    for(int i = 0 ; i < str.size(); ++i)
    {
        cout<< " " << str[i] ;
    }

    cout << endl;

    return 0;
}