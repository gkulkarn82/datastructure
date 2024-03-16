#include<bits/stdc++.h>
using namespace std;

class Queue
{
	int rear, front, size;
	int* array;

public:
	Queue(int size)
	{
		front = rear = -1;
		this->size = size;
		array = new int[size];		
	}

	void enQueue(int value);
	int deQueue();
	void display();
};

void Queue:: enQueue(int value)
{
	// condition for full
	if((front == 0 && rear == size -1) || front == rear + 1)   //((rear + 1) % size == front))
	{
		cout << "\nQueue is full";
		return;
	}

	// if Queue is empty and this is first element
	else if(front == -1)
	{
		front = rear = 0;
		array[rear] = value;
	}
	// if the front has moved ahead than 0 means there is space remaining
	// and rear has reached to end hence need to set rear to 0
	else if(rear == size - 1  && front != 0)
	{
		rear = 0;
		array[rear] = value;
	}
	else
	{
		rear++;
		array[rear]= value;
	}
	
}

int Queue:: deQueue()
{
	if(front == -1)
	{
		cout << "Queue is empty" << endl;
		return -1;
	}

	int data = array[front];
	array[front] = -1;

	// check if front and rear are at same position 
	// then reset it to -1
	if(front == rear)
		front = rear = -1;
	// if front  has reach to end then reset it to 0
	else if(front == size -1)
		front = 0;
	//else just increment front and return data
	else
		front++;

	return data;
}

void Queue::display()
{
	if(front == -1)
	{
		cout << "\nQueue is empty" << endl;
		return ;
	}
	printf("\nElements in Circular Queue are: ");
	if(rear >= front)
	{
		for(int i = front; i <= rear; i++)
			cout << array[i] << " " ;
	}
	else
	{
		for(int i = front; i < size; i++)
			cout << array[i] << " ";

		for(int i = 0; i <= rear; i++)
			cout << array[i] << " ";
	}
}

int main()
{
    Queue q(5);
 
    // Inserting elements in Circular Queue
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);
 
    // Display elements present in Circular Queue
    q.display();
 
    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.deQueue());
    printf("\nDeleted value = %d", q.deQueue());
 
    q.display();
 
    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);
 
    q.display();
 
    q.enQueue(20);
    return 0;
}