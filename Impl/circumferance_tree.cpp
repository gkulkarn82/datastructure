#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value):val(value), left(nullptr), right(nullptr)
    {

    }
};

class Solution
{
public:
    void printCircumference(TreeNode* root)
    {
        if(root)
        {
            cout << root->val << " ";
            printLeftBoundary(root->left);
            printLeafNodes(root->left);
            printLeafNodes(root->right);
            printRightBoundary(root->right);
        }
    }
private:
    void printLeftBoundary(TreeNode* node)
    {
        while(node)
        {
            if(node->left || node->right)
                cout << node->val << " ";
            if(node->left)  
                node = node->left;
            else
                node = node->right;
        }
    }

    void printRightBoundary(TreeNode* node)
    {
        //std::vector<int> vals;
        while(node)
        {
            if(node->left || node->right)
                cout << node->val << " ";
                //vals.insert(vals.begin(), node->val);
            if(node->right) 
                node = node->right;
            else 
                node = node->left;            
        }
        // for(int val: vals)
        //     cout<< val << " ";
    }

    void printLeafNodes(TreeNode* node)
    {
        if(node)
        {
            printLeafNodes(node->left);
            if(!node->left && !node->right)
                cout << node->val << " ";
            printLeafNodes(node->right);
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;
    solution.printCircumference(root);

    // Clean up memory (not shown in detail here)
    
    return 0;
}