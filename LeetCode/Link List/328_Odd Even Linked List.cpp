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
    ListNode* oddEvenList(ListNode* head) {
        // ListNode* odd = new ListNode(-1);
        // ListNode* temp = odd;
        // ListNode* even = new ListNode(-1);
        // ListNode* temp2 = even;

        // ListNode* curr = head;

        // while(curr)
        // {
        //     if(curr->val & 1)
        //     {
        //         odd->next = curr;
        //         odd = odd->next;
        //         curr = curr->next;
        //         odd->next = NULL;
        //     }
        //     else
        //     {
        //         even->next = curr;
        //         even = even->next;
        //         curr = curr->next;
        //         even->next = NULL;
        //     }
        // }
        // odd->next = temp2->next;
        // return temp->next;

        // if(!head || !head->next || !head->next->next)
        //     return head;

        // ListNode* odd_indices = head;
        // ListNode* even_indices = head->next;
        // ListNode* even_indices_start = head->next;

        // while(odd_indices->next && even_indices->next)
        // {
        //     odd_indices->next = even_indices->next;
        //     even_indices->next = odd_indices->next->next;
        //     odd_indices = odd_indices->next;
        //     even_indices = even_indices->next;
        // }
        // odd_indices->next = even_indices_start;
        // return head;

        //Approach III
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
                return head;

        bool isOdd = true;
        ListNode oddIndices(0);
        ListNode evenIndices(0);
        ListNode* temp = head;
        ListNode* oi = &oddIndices;
        ListNode* ei = &evenIndices;

        while(temp != nullptr)
        {
            if(isOdd)
            {
                oi->next = temp;
                oi = oi->next;
            }
            else
            {
                ei->next = temp;
                ei = ei->next;
            }
            temp = temp->next;
            isOdd = !isOdd;
        }
        oi->next = nullptr;
        ei->next = nullptr;

        oi->next = evenIndices.next;
        return oddIndices.next;
        
        /*
            case I  1   2    3 ->   4  ->   5
                                    ei    oi
        
        
        */





















































    }
};