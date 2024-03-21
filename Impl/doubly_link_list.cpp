#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void insert_front(struct Node** head, int item)
{
    struct Node* newNode = new Node;

    newNode->data = item;
    newNode->next =(*head);

    if(*head != NULL)
        (*head)->prev = newNode; //newNode->next->prev = newNode; both works same
    newNode->prev = NULL;
    (*head) = newNode;
}

void insert_after(Node* head, int item)
{
    struct Node* newNode = new Node;
    newNode->data = item;    

    if(head->next)
        newNode->next = head->next;
    head->next->prev= newNode;
    newNode->prev = head;
}

void insert_end(Node** head, int item)
{
    cout << "1" << endl;
    struct Node* newNode = new Node;
    struct Node* last = *head;

    newNode->data = item;
    newNode->next = NULL;
    
    if(*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    cout << "2" << endl;
    while(last && last->next != NULL)
        last = last->next;

    cout << "3" << endl;
    last->next = newNode;
    newNode->prev = last;
    return;
}

void displayList(struct Node* node) {
   struct Node* last;
  
   while (node != NULL) {
      cout<<node->data<<"<==>";
      last = node;
      node = node->next;
   }
   if(node == NULL)
   cout<<"NULL";
}

int main()
{
    struct Node* head = NULL;
    insert_end(&head, 40);
    insert_front(&head, 20);
    insert_front(&head, 10);
    insert_end(&head, 50);

    insert_after(head->next, 30);
    cout<<"Doubly linked list is as follows: "<<endl;
    displayList(head);
    return 0;
}