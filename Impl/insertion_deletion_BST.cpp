/*
How to Insert a value in a Binary Search Tree:
A new key is always inserted at the leaf by maintaining the property of the binary search tree. 
We start searching for a key from the root until we hit a leaf node. Once a leaf node is found, 
the new node is added as a child of the leaf node. 

The below steps are followed while we try to insert a node into a binary search tree:

Check the value to be inserted (say X) with the value of the current node (say val) we are in:
If X is less than val move to the left subtree.
Otherwise, move to the right subtree.
Once the leaf node is reached, insert X to its right or left based on the relation between X and the 
leaf node’s value.
Follow the below illustration for a better understanding:

*/
#include<iostream>
using namespace std;

class BST
{
    int data;
    BST *left, *right;

    public:
        BST();
        BST(int);
        BST* insert(BST*, int);
        BST* insertItrative(BST*& root, int key);
        void inorder(BST*);
        BST* deleteNode(BST* root, int key);
};

BST::BST():data(0), left(nullptr), right(nullptr)
{

}

BST::BST(int val)
{
    data = val;
    left = right = nullptr;
}

//Recursive
BST* BST::insert(BST* root, int val)
{
    if(!root)
        return new BST(val);

    if(val > root->data)
        root->right = insert(root->right, val);
    else if(val < root->data)
        root->left = insert(root->left, val);

    return root;
}

//Iterative
BST* BST::insertItrative(BST*& root, int key)
{
    BST* node = new BST(key);
    if (!root) {
        root = node;
        return;
    }
    BST* prev = NULL;
    BST* temp = root;
    while (temp) {
        if (temp->data > key) {
            prev = temp;
            temp = temp->left;
        }
        else if (temp->data < key) {
            prev = temp;
            temp = temp->right;
        }
    }
    if (prev->data > key)
        prev->left = node;
    else
        prev->right = node;

    return root;
}

BST* BST::deleteNode(BST* root, int key)
{
    if(!root)
        return root;

    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }

    if(root->left == nullptr)
    {
        BST* temp = root->right;
        delete root;
        return temp;
    }
    else if(root->right == nullptr)
    {
        BST* temp = root->left;
        delete root;
        return temp;
    }

    // This is the code to find the inorder sucessor or child
    //as that child will be less than any of it's parent and will be greater than any element from
    // left side of the tree hence child is initialised to root->right
    BST* parent = root;
    BST* child = root->right;
    while(child->left != nullptr)
    {
        parent = child;
        child = child->left;
    }

    root->data = child->data;

    if(parent->left == child)
        parent->left = child->right;
    else
        parent->right = child->right;

    delete child;
    return root;    
}

void BST::inorder(BST* root)
{
    if(!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main()
{
    BST b, *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);
 
    b.inorder(root);
    return 0;
}