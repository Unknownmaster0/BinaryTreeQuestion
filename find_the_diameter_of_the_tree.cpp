/*Diameter of the tree -> The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. */
#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // making the constructor
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


// function for the max height of the tree
int height(Node* root)
{
    if(root == NULL)
        return 0;
        
    int left = height(root->left);
    int right = height(root->right);
    
    return max(left,right)+1;
}

pair<int,int> fastDiameter(Node*root)
{
    if(root == NULL)
    {
        return {0,0};
    }
    
    // go to the left part
    pair<int,int>left = fastDiameter(root->left);
    
    // go to the right part
    pair<int,int>right = fastDiameter(root->right);
    
    // diameter of left
    int op1 = left.first;
    
    // diameter of right
    int op2 = right.first;
    
    int op3 = left.second + right.second + 1;
    
    pair<int,int>ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second , right.second) + 1;
    
    return ans;
}

// Function to return the diameter of a Binary Tree.
int diameter(Node* root) {
    
    
    return fastDiameter(root).first;
    
    /* The below method will give you TLE because here the time complexity -> O(n^2) */
    /*
    if(root == NULL)
        return 0;
    
    // when the ans lies in left subtree
    int op1 = diameter(root->left);
    
    // when the ans lies in right sub-tree
    int op2 = diameter(root->right);
    
    // when the ans lies in both right and left sub-tree
    int op3 = height(root->left) + height(root->right) + 1;
    
    // return the maximum of the op1,op2 and op3
    return max(op1, max(op2,op3));
    */
    
}



int main()
{
    
    return 0;
}