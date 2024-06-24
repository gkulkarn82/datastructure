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
    ListNode* swapH(ListNode* head, int k)
    {
        if(head == nullptr || head->next == nullptr)
            return head;

        int length = 0;
        ListNode* temp = head;

        while(temp != nullptr)
        {
            ++length;
            temp = temp->next;
        } 
        if(length < k) return head;

        int count = 0;
        ListNode* curr = head;
        ListNode* next = head;
        ListNode* prev = nullptr;

        while(curr != nullptr && count < k)
        {
            count++;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = swapH(curr, k);
        return prev;
    }
public:
    ListNode* swapPairs(ListNode* head) {    
        //Approach I - Brute Force
        // copying data in vector and then doing swap and then putting it to link list again
        // if(head == nullptr)
        //     return nullptr;
        // vector<int> vs;       
        // ListNode* curr = head;
        // ListNode* dummy = new ListNode(-1);
        // ListNode* temp = dummy;

        // while(curr != NULL)
        // {
        //     vs.push_back(curr->val);
        //     curr = curr->next;
        // }

        // // This code fails if we use vs.size instead of vs.size() - 1
        // for(int i = 0 ; i < vs.size() - 1; i+=2)
        // {
        //     cout << "before i = " << i << endl;
        //     swap(vs[i], vs[i +1]);  
        //     cout << "after i = " << i << endl;
        // }
    
       
        // for(int i = 0; i < vs.size() ; i++)
        // {              
        //     ListNode* newnode = new ListNode(vs[i]);        
        //     dummy->next = newnode;           
        //     dummy = dummy->next;
        // }       
        // return temp->next;

                
        // Approach II Iterative
        // if(head == nullptr || head->next == nullptr) 
        //     return head;

        // ListNode* newHead = head->next;
        // ListNode* p1 = head;
        // ListNode* p2 = head->next;        
        // p1->next = p2->next;
        // p2->next = p1;
        // ListNode* prev = nullptr;
        
        // while(p1 != nullptr && p1->next != nullptr && p1->next->next != nullptr)
        // {
        //     prev = p1;
        //     p1 = p1->next;
        //     p2 = p1->next;
        //     p1->next = p2->next;
        //     p2->next = p1;
        //     prev->next = p2;            
        // }

        // return newHead;

        /*
            1       2       3         4
           100      200     300       400        head = 100

           200      100     400       300        head = 100   return head->next = 400        
        */


        //Approach III Recursion
        if(head == nullptr || head->next == nullptr)
            return head;

        return swapH(head, 2);
    }
};