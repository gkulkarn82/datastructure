//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        if(!head || !head->next)
        {
            return head;
        }
        
        //3 pointers
        Node obj0(0),obj1(0),obj2(0);
        Node* p0= &obj0;
        Node* p1= &obj1;
        Node* p2= &obj2;
        Node* temp = head;
        
        while(temp)
        {
            switch(temp->data)
            {
                case 0:
                    p0->next = temp;
                    p0 = p0->next;
                    break;
                case 1:
                    p1->next = temp;
                    p1 = p1->next;
                    break;
                case 2:
                    p2->next = temp;
                    p2 = p2->next;
                    break;
            }
            temp = temp->next;
        }
        p0->next = nullptr;
        p1->next = nullptr;
        p2->next = nullptr;
        
        if(obj0.next)
        {
            if(obj1.next)
            {
                p0->next = obj1.next;
                if(obj2.next)
                {
                    p1->next = obj2.next;
 
                }
            }
            else if(obj2.next)
            {
                p0->next = obj2.next;
            }
            
            return obj0.next;
        }
        
        //obj0.next is null
        //head -1 or 2
        if(obj1.next)
        {
            if(obj2.next)
            {
                p1->next = obj2.next;
            }
            return obj1.next;
        }
        
        return obj2.next;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends