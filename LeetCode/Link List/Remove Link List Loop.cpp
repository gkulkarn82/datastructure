/*
    Remove loop from a linked list
-------------------------------

1. Take slow and fast ptr starting from head. And prev = nullptr (this is to remove loop)
2. In a while loop (fast != nullptr && fast->next != nullptr)
	move slow to slow->next
	move prev to fast->next (this is required here to handle corner case where last node is creating loop with first node)
	move fast tp fast->next->next
	If slow == fast means loop found and this is loop detection node (this is not necessarily lopp start node)
3. Now take move the slow to head of list and let fast stay at loop detection node
4. Run a while loop with (slow != fast)
	keep the track of previous of the fast pointer
	if(slow == fast) means node is start of the loop

5 Now, prev is pointing to previous node of fast, so break the loop by setting prev->next = nullptr

*/


//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node *head, unordered_map<Node *, int>&myMap){
    
    while(head){
        if(myMap.find(head)==myMap.end()) return true;
        if(myMap[head] != (head->data)) return true;
        
        head=head->next;
    }
}




// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if(head == nullptr || head->next == nullptr)
            return;
        
        Node* slow = head, *fast = head, * prev = nullptr;
        while(fast != NULL && fast->next !=  NULL){
            slow = slow->next;
            prev = fast->next;
            fast = fast->next->next;
            
            if (slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    prev = fast;
                    fast = fast->next;
                }
                prev->next = nullptr ;
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<Node *, int>myMap;
        
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        myMap[head]=num;
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail]=num;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n || notOriginal(head, myMap))
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends