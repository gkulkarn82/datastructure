#include<iostream>
#include<stack>
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
    bool IsPalindromeHelper(ListNode*& start, ListNode* end)
    {
        if(end == nullptr) return true;
        
        if(!IsPalindromeHelper(start, end->next)) return false;
        if(start->val != end->val) return false;
        
        start = start->next;
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        //Approach I
        //Processing only half elements using stack
        //  if(head == nullptr || head->next == nullptr)
        //         return true;

        // ListNode* slow = head, *fast = head;
        // while(fast != nullptr && fast->next != nullptr)
        // {
        //     // This is to handle corner case with only 2 nodes [1,2]
        //     fast = fast->next->next;    
        //     if(fast == nullptr)
        //         break;
        //     slow = slow->next;                    
        // }        

        // stack<int> st;
        // ListNode* temp = slow->next;
        // while(temp != nullptr)
        // {
        //     st.push(temp->val);
        //     temp = temp->next;
        // }

        // temp = head;
        // while(!st.empty())
        // {
        //     if(temp->val != st.top())
        //         return false;
        //     st.pop();
        //     temp = temp->next;
        // }
        // return true;


        //Approach II
        //Processing only all elements using stack       
        // ListNode* curr = head;
        // stack<ListNode*> s;
        // while(curr != NULL)
        // {
        //     s.push(curr);
        //     curr = curr->next;
        // }         

        // while(!s.empty() && head != NULL)
        // {
        //     ListNode* node = s.top();
        //     s.pop();

        //     if(node->val != head->val)
        //         return false;
        //     else
        //     {
        //     head = head->next;
        //     }
        // }

        // return true;

        //Approach III Recursion
        if(head == nullptr || head->next == nullptr) return true;            
        return IsPalindromeHelper(head, head);     
    }
};