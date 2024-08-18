//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
/*
The structure of linked list is the following

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
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        //Approach I Using Map and Vector
        // std::unordered_map<int, Node*> listMap;
        // std::vector<std::pair<int, Node*>> vecPair;

        // Node* curr = head;
        // while(curr != nullptr)
        // {
        //     auto it = listMap.emplace(curr->data, curr) ;
        //     if(it.second == true)
        //     {
        //         vecPair.push_back(std::pair<int, Node*>(curr->data, curr));
        //     }
        //     curr = curr->next;           
        // }
        
        // Node temp_node(0);
        // Node* preHead = &temp_node;

        // for(auto it = vecPair.begin(); it != vecPair.end(); ++it)
        // {
        //     preHead->next = it->second;
        //     preHead = preHead->next;
        // }
        // preHead->next = nullptr;
        // return temp_node.next;  


        //Approach II
        unordered_set<int> seen;
        Node* curr = head;
        Node* prev = nullptr;

        while(curr != nullptr)
        {
          if(seen.find(curr->data) != seen.end())
          {
              prev->next = curr->next;
              delete(curr);
          }
          else
          {
             seen.insert(curr->data);
             prev = curr;
          }
          curr = prev->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
    struct Node *temp = head;
 
		for(int i=0;i<K;i++)
    {
		    int data;
		    cin>>data;
        if(head==NULL)
          head=temp=new Node(data);
        else
        {
          temp->next = new Node(data);
          temp=temp->next;
        }
		}
		
	  Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends