#include<iostream>
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
private:    
    // ListNode* merge(ListNode* list1, ListNode* list2)
    // {
    //     ListNode* result = new ListNode(0);
    //     ListNode* curr = result;

    //     while(list1 != nullptr && list2 != nullptr)
    //     {
    //         if(list1->val < list2->val)
    //         {
    //             curr->next = list1;
    //             list1 = list1->next;
    //         }
    //         else
    //         {
    //             curr->next = list2;
    //             list2 = list2->next;
    //         }
    //         curr = curr->next;
    //     }

    //     if(list1)
    //         curr->next = list1;
    //     if(list2)
    //         curr->next = list2;

    //     return result->next;
    // }

    ListNode* findMid(ListNode* head)
    {      
        ListNode* slow = head , *fast = head->next;
        while(fast != nullptr && fast->next != nullptr)
        {          
            fast = fast->next->next;           
            slow = slow->next;          
        }
        return slow;
    }

    ListNode* mergeSortedList(ListNode* first, ListNode* second)
    {       
        ListNode tempObj(0);
        ListNode* temp1 = &tempObj;

        while(first != nullptr && second != nullptr)
        {
            if(first->val < second->val)
            {
                temp1->next = first;
                first = first->next;
                temp1= temp1->next;
               
            }
            else
            {
                temp1->next = second;
                second = second->next;
                temp1= temp1->next;                
            }            
        }

        if(first)
            temp1->next = first;
        if(second)
            temp1->next = second;

        return tempObj.next;
    }
public:
    ListNode* sortList(ListNode* head) {

        //Appraoch III
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* midNode = findMid(head);
        ListNode* first = head;
        ListNode* second = midNode->next;

        midNode->next = nullptr;
        first = sortList(first);
        second = sortList(second);
        return mergeSortedList(first, second);

        // Appraoch I Brute Force
        // ListNode* out = new ListNode();
        // ListNode* temp = out;       
        // vector<int> v ;        

        // while(head)
        // {
        //     v.push_back(head->val);
        //     head = head->next;
        // }
        // sort(v.begin(), v.end());
        // //out = out->next;
        // for(auto i: v)
        // {
        //     cout << "Value if i = " << i << endl;
        //     ListNode* newnode = new ListNode(i);
        //     temp->next = newnode;
        //     cout << "out val =" << temp->val <<endl;
        //     temp = temp->next;
        // }
        // cout <<"temp->next = " << out->val << endl;
        // out = out->next;
        // return out;

        // Approach II Merge Sort
        //     if(head == NULL || head->next == NULL)
        //         return head;

        //     ListNode* slow = head;
        //     ListNode* fast = head->next;
        //     ListNode* temp = NULL;

        //     while(fast != NULL && fast->next != NULL)
        //     {           
        //         slow = slow->next;
        //         fast = fast->next->next;
        //     };
        //     temp = slow->next;
        //     slow->next = NULL;

        //     return merge(sortList(head), sortList(temp));

    }
};