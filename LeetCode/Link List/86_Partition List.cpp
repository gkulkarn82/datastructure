#include<bits/stdc++.h>
#include<thread>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {

public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummyHead1 = new ListNode();
        ListNode* temp = dummyHead1;
        ListNode* dummyHead2 = new ListNode();
        ListNode* temp1 = dummyHead2;

        while(head != nullptr)
        {
            if(head->val < x)
            {
                temp->next = new ListNode(head->val);
                temp = temp->next;
                head = head->next;                
            }
            else
            {
                temp1->next = new ListNode(head->val);
                temp1 = temp1->next;
                head = head->next; 
            }
        }
        temp->next = dummyHead2->next;
        return dummyHead1->next;

        // ListNode* lesser = new ListNode(-1);
        // ListNode* temp1 = lesser;
        // ListNode* greater = new ListNode(-1);
        // ListNode* temp2 = greater;
                 
        // while(head)
        // {
        //     if(head->val < x)
        //     {
        //         lesser->next = head;
        //         lesser = lesser->next;
        //         head = head->next;
        //         lesser->next = NULL; //if we dont make it null whole list after head will be added to this node
        //     }
        //     else
        //     {
        //         greater->next = head;
        //         greater = greater->next;
        //         head = head->next;
        //         greater->next= NULL;
        //     }          
        // }
        // lesser->next = temp2->next;
        // return temp1->next;
    }
};