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
public:
    ListNode* deleteDuplicates(ListNode* head) {

        //Approach I Getting rid of memory leak
        ListNode dummy(0);
        ListNode* preHead = &dummy ;
        
        ListNode* p1 = head;
        ListNode* p2 = head;
        
        while(p2 != nullptr)
        {
            p1 = p2;
            ListNode* node_to_delete = nullptr;
            while(p2->next && p2->val == p2->next->val)
            {
                // This code is for deleting the duplicate nodes till it's detection 
                // else it's memory will be leak
                if(node_to_delete != nullptr)
                    delete node_to_delete;
                node_to_delete = p2->next;
                p2 = p2->next;
            }
            if(p2 != nullptr)
                p1->next = p2->next;
            else
            {
                p1->next = nullptr;
                break;
            }
            p2 = p2->next;

        }
        return head;

        //Approach II
        // std::map<int, ListNode*> listMap;

        // ListNode* curr = head;
        // while(curr != nullptr)
        // {
        //     auto out = listMap.emplace(curr->val, curr) ;
        //     if(!out.second)
        //     {
        //         std::unique_ptr<ListNode> temp(curr);
        //         curr = curr->next;
        //     }
        //     else
        //         curr = curr->next;           
        // }
        
        // ListNode temp_node(0);
        // ListNode* preHead = &temp_node;

        // for(auto it = listMap.begin(); it != listMap.end(); ++it)
        // {
        //     preHead->next = it->second;
        //     preHead = preHead->next;
        // }
        // preHead->next = nullptr;
        // return head;  
        
        
        //Approach III
        // if(head == NULL )
        //     return head;

        // ListNode* out = new ListNode(0);
        // ListNode* current = out;

        // while(head)
        // {
        //     while(head->next && head->val == head->next->val)
        //         head = head->next;
        //     current->next = head;
        //     current= current->next;
        //     head = head->next;
        // }
        // return out->next;
    }
};