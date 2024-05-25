#include<bits/stdc++.h>
#include <thread>
using namespace std;

Node* MergeLinkList(Node* l1, Node* l2)
{
    if(l1 == nullptr)
        return l2;
    if(l2 == nullptr)
        return l1;  

    Node* head = nullptr;
    if(l1->data <= l2->data)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next
    }

    Node* temp = head;
    while(l1 != nullptr && l2 != nullptr)
    {
        if(l1->data >= l2->data)
        {
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }
        else
        {
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }
    }

    if(l1)
        temp->next = l1;

    if(l2)
        temp->next = l2;

    return head; 
}


/*

L1 = 1->2->3
L2 = 4->5->6
Head = 1
temp = 1->2->3->l2(4->5->6)

*/