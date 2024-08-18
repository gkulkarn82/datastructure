/*
The standard deletion operation on Heap is to delete the element present at the root node of the Heap. 
That is if it is a Max Heap, the standard deletion operation will delete the maximum element and if it 
is a Min heap, it will delete the minimum element.

Process of Deletion: 
Since deleting an element at any intermediary position in the heap can be costly, so we can simply replace 
the element to be deleted by the last element and delete the last element of the Heap. 

Replace the root or element to be deleted by the last element.
Delete the last element from the Heap.
Since, the last element is now placed at the position of the root node. So, it may not follow the heap 
property. Therefore, heapify the last node placed at the position of root.

Illustration:
Suppose the Heap is a Max-Heap as:
      10
    /    \
   5      3
  / \
 2   4
The element to be deleted is root, i.e. 10.
Process:
The last element is 4.
Step 1: Replace the last element with root, and delete it.
      4
    /    \
   5      3
  / 
 2   
Step 2: Heapify root.
Final Heap:
      5
    /    \
   4      3
  / 
 2   

Process of Insertion: Elements can be inserted to the heap following a similar approach as discussed above 
for deletion. The idea is to: 

First increase the heap size by 1, so that it can store the new element.
Insert the new element at the end of the Heap.
This newly inserted element may distort the properties of Heap for its parents. So, in order to keep the 
properties of Heap, heapify this newly inserted element following a bottom-up approach. 

Illustration:  

Suppose the Heap is a Max-Heap as:
      10
    /    \
   5      3
  / \
 2   4
The new element to be inserted is 15.
Process:
Step 1: Insert the new element at the end.
      10
    /    \
   5      3
  / \    /
 2   4  15
Step 2: Heapify the new element following bottom-up 
        approach.
-> 15 is more than its parent 3, swap them.
       10
    /    \
   5      15
  / \    /
 2   4  3
-> 15 is again more than its parent 10, swap them.
       15
    /    \
   5      10
  / \    /
 2   4  3
Therefore, the final heap after insertion is:
       15
    /    \
   5      10
  / \    /
 2   4  3

*/

#include<iostream>
using namespace std;

void heapifyDelete(int arr[], int n, int i)
{
    //consider the first elemenet as the largest
    int largest = i;

    int l = 2 * i + 1; // to get the left element of i element
    int r = 2 * i + 2; // to get the right element of the i element

    /*
        Here we are checking if the largest if not greater than it's left or right
        then the element l or r i.e left or right becomes largest.

        it means that the tree is not following the property of max heap.
        we need to make it max or min heap based on the condition.

        Currently this code denotes or written for max heap.so greater condition is checked
        for min heap it will check the lesser
    */
    if(l < n && arr[l] > arr[largest])
        largest = l;
    if(r < n && arr[r] > arr[largest])
        largest = r;

    if(largest != i)
    {
        //swap the node since the largest element and element provided is not same i.e i
        //here we will swap and again run the heapify to make it follow the property of
        //max heap
        swap(arr[i] , arr[largest]);

        //Run in recursion till the tree becomes max heap
        heapifyDelete(arr, n , largest);
    }
}

void heapifyInsert(int arr[], int n, int i)
{
    //Here we need to find the parent . The reason is in max heap the parent should be greater than child
    //and parents location in array is position divide by 2
    int parent = (i - 1) / 2;

    //check if the parent position is greater than or equal to 0
    if(parent >= 0)
    {
        //If the elemenent is greater than parent it means it's not following the property of max heap
        //So we need to swap them and continue check rest of the elements till it reaches the the top
        if(arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);
            heapifyInsert(arr, n, parent);
        }
    }
}

void insertNode(int arr[], int n, int key)
{
    //Add the element at the end of the array
    //for that increase the size of an array
    n = n + 1;

    arr[n - 1] = key;

    //Now since we are adding the element at the end we need to check if the tree follows the rule
    //of max heap here if not we need to make it max heap
    heapifyInsert(arr, n , n - 1);
}

void deleteRoot(int arr[], int n)
{
    //Get the last element as we want to delete the root
    //we generally repalce it with last element and then delete the last one
    int lastElement = arr[n - 1];

    //Assign first element with the last element
    arr[0] = lastElement;

    //Decrease the size of an array by 1
    n = n - 1;

    //Now we need to check if the tree follows the rule of max heap
    //i.e the bigger number should be at the top of every child node
    heapifyDelete(arr, n , 0);
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    // Array representation of Max-Heap
    //     10
    //    /  \
    //   5    3
    //  / \
    // 2   4

    int arr[] = { 10, 5, 3, 2, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    //deletion
    deleteRoot(arr, n);
    printArray(arr, n);

    //insertion
    int key = 15;
    insertNode(arr,n , key);
    printArray(arr, n);


    return 0;
}
























