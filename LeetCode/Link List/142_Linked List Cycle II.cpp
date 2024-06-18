#include<bits/stdc++.h>
#include<thread>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        // Approach I Using Unordered_map
        unordered_set<ListNode*> uset;
        ListNode* temp = head;       
        while (temp != nullptr) {
            if (uset.find(temp->next) != uset.end())
                return temp->next;
            uset.insert(temp);        
            temp = temp->next;
        }
        return nullptr;

        // ListNode* slow = head, *fast = head;
        // while(fast != NULL && fast->next !=  NULL){
        //     slow = slow->next;
        //     fast = fast->next->next;
        //     if (slow == fast){
        //         slow = head;
        //         while(slow != fast){
        //             slow = slow->next;
        //             fast = fast->next;
        //         }
        //         return slow ;
        //     }
        // }
        // return NULL ;

        //Approach III
        // if(head == nullptr || head->next == nullptr)
        //     return nullptr;

        // ListNode* slow = head->next , *fast = head->next->next;        
        // while(fast != nullptr && fast->next != nullptr)
        // {            
        //     if(fast == slow)
        //         break;
        //     fast = fast->next->next;
        //     slow = slow->next;
        // } 
        // if(fast != slow)
        // {
        //     return nullptr;
        // }
        // slow = head;
        // while(slow != fast)
        // {
        //     slow = slow->next;
        //     fast = fast->next;
        // }
        // return slow;
    }
};