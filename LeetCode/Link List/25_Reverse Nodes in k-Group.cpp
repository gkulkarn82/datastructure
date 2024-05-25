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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;

        int length = 0;
        ListNode* countHead = head;
        while(countHead != nullptr)
        {
            ++length;
            countHead = countHead->next;
            if(length > k)
                break;
        }

        if(k > length)
            return head;

        int counter = 0;
        ListNode *curr = head;
        ListNode *prev = nullptr, *next = nullptr;        

        while(counter < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++counter;
        }

        head->next = reverseKGroup(curr, k);
        return prev;
    }
};