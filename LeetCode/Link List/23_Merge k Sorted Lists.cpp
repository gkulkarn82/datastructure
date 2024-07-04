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
class Solution {
    struct GreaterVal
    {
        bool operator()(ListNode* first, ListNode* second)
        {
            return (first->val > second->val);
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, GreaterVal> pq;
        
        if(lists.size() == 0) 
            return nullptr; 

        for(int i = 0; i < lists.size(); ++i)
        {
            if(lists[i] != nullptr)
                pq.push(lists[i]);
        }

        ListNode preHead(0);
        ListNode* temp = &preHead;

        while(!pq.empty())
        {
            temp->next = pq.top();
            pq.pop();

            if(temp->next->next != nullptr)
                pq.push(temp->next->next);
            temp = temp->next;
        }

        return preHead.next;
    }
};