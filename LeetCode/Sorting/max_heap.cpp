/*
A max heap and min heap are types of priority queues, where the elements are organized in a way that the 
largest (or smallest) element is at the root of the heap, and the elements are ordered in a way that the parent node 
is either greater than (or less than) its child nodes. The main difference between a max heap and a min heap is the direction 
of the ordering, with a max heap having the largest element at the root and a min heap having the smallest element at the root.


Purpose and Use Cases of Max-Heap:

Priority Queue: One of the primary uses of the heap data structure is for implementing priority queues. 

Heap Sort: The heap data structure is also used in sorting algorithms.  

Memory Management: The heap data structure is also used in memory management. When a program needs to allocate memory dynamically, 
it uses the heap data structure to keep track of the available memory. 

Graph Algorithms: The heap data structure is used in various graph algorithms. 
For example, Dijkstra’s shortest path algorithm uses a heap data structure to keep track of the vertices with the 
shortest path from the source vertex. 

ref : https://www.youtube.com/watch?v=NKJnHewiGdc

*/

/*
    If you need to find the left and right node of the node then
    e.g if the node is at ith index then 
    left Node can be found at (2 * i) th index
    right Node can be found at  (2 * i ) + 1 th index

    [X, 60, 50, 40, 30, 20]
     0   1  2    3   4   5 
 
*/
#include<bits/stdc++.h>
using namespace std;

class heap
{
    public:
        int arr[100];
        int size = 0;

        heap()
        {
            arr[0] = -1;
            size = 0;
        }

        void insert(int val)
        {
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1)
            {
                int parent = index / 2;

                if(arr[parent] < arr[index])
                {
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else
                    return;
            }           
        }

        void print()
        {
            for(int i = 1; i <= size; i++ )
                cout << arr[i] << " ";
            cout << endl;
        }

        void deletefromheap()
        {
            if(size == 0)
            {
                cout << "nothing to delete" << endl;
                return ;
            }

            //assign last node to root and then start doing the readjustment based on max heap
            // i.e getting the higest number at the top
            arr[1] = arr[size];
            size-- ; // delete the last node as it is assigned to first node

            //Lets iterate to make it max heap

            int i = 1;
            while(i < size)
            {
                //get left index
                int leftindex = 2 * i;
                int rightindex = 2 * i + 1;

                if(leftindex < size && arr[i] < arr[leftindex])
                {
                    swap(arr[i], arr[leftindex]);
                    i = leftindex;
                }
                else if(rightindex < size && arr[i] < arr[rightindex])
                {
                    swap(arr[i], arr[rightindex]);
                    i = rightindex;
                }
                else
                    return;
            }

        }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left =  2 * i;
    int right = 2 * i + 1;

    //if it is 0 based indexing then this logic is corect
    //else if 1 based indexing then we need to change condition to 
    //left <=n && right <=n
    if(left <= n && arr[largest] < arr[left])
        largest = left;
    if(right <= n &&  arr[largest] < arr[right])
        largest = right;

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n , largest);
    }
}

void heapsort(int arr[], int n)
{
    int size = n;
    while(size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletefromheap();
    h.print();


    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
    
    for(int i = n/2; i > 0; i--)
    {
        heapify(arr, n , i);
    }
    cout << "Printing the array now " << endl;

    for(int i = 1 ; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;   

    heapsort(arr, n);
    for(int i = 1 ; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cin.get();
    return 0;
}
