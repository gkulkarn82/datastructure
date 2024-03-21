#include<bits/stdc++.h>
using namespace std;

#define MAX 100

class Deque
{
    int arr[MAX];
    int front;
    int rear;
    int size;
public:
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }

    void insertfront(int key);
    void insertrear(int key);
    void deletefront();
    void deleterear();
    bool isFull();
    bool isEmpty();
    int getfront();
    int getrear();
};

bool Deque::isFull()
{
    return ((front == 0 && rear == size - 1) || front == rear + 1);
}

bool Deque::isEmpty()
{
    return (front == -1);
}

void Deque::insertfront(int key)
{
    if(isFull())
    {
        cout << "Overflow\n";
        return;
    }

    if(front == -1)
    {
        front = rear = 0;
    }
    else if(front == 0)
    {
        front = size -1;
    }
    else
        front--;
        
    arr[front] = key;
}

void Deque::insertrear(int key)
{
    if(isFull())
    {
        cout << "Overflow\n";
        return;
    }
    if(front == -1)
    {
        front = rear = 0;
    }
    else if(rear == size - 1)
        rear = 0;
    else
        rear++;

    arr[rear] = key;
}

void Deque::deletefront()
{
    if(isEmpty())
    {
        cout << "Underflow\n";
        return;
    }

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == size - 1)
        front =0;
    else
        front = front + 1;
}

void Deque::deleterear()
{
    if (isEmpty()) {
        cout << " Underflow\n" << endl;
        return;
    }
 
    // Deque has only one element
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size - 1;
    else
        rear = rear - 1;
}

int Deque::getfront()
{
    if(isEmpty())
    {
        cout << "Underflow\n";
        return -1;
    }
    return arr[front];
}

int Deque::getrear()
{
    if(isEmpty() || rear < 0)
    {
        cout << "Underflow\n";
        return -1;
    }
    return arr[rear];
}

int main()
{
    Deque dq(5);
   
      // Function calls
    cout << "Insert element at rear end  : 5 \n";
    dq.insertrear(5);
 
    cout << "insert element at rear end : 10 \n";
    dq.insertrear(10);
 
    cout << "get rear element "
         << " " << dq.getrear() << endl;
 
    dq.deleterear();
    cout << "After delete rear element new rear"
         << " become " << dq.getrear() << endl;
 
    cout << "inserting element at front end \n";
    dq.insertfront(15);
 
    cout << "get front element "
         << " " << dq.getfront() << endl;
 
    dq.deletefront();
 
    cout << "After delete front element new "
         << "front become " << dq.getfront() << endl;
    return 0;
}
