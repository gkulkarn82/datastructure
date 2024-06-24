//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        if(head == nullptr || head->next == nullptr)
            return head;
            
        Node evenHead(0);
        Node oddHead(0);
        Node* temp = head;
        Node* pe =&evenHead;
        Node* po =&oddHead;
        
        while(temp)
        {
            if(temp->data %2 == 0)
            {
                pe->next = temp;
                pe = pe->next;
            }
            else
            {
                po->next = temp;
                po = po->next;
            }
            temp = temp->next;
        }
        pe->next = nullptr;
        po->next = nullptr;
        
        if(evenHead.next != nullptr)
        {
            pe->next = oddHead.next;
            return evenHead.next;
        }
        return oddHead.next;
        
        /*
            case I => 1 3 5 7 9       ==
            case II => 2 4 6 8 10     ==
            case III => 1 2 3 4 5 6 7 8 9 10
        
        
        */
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends