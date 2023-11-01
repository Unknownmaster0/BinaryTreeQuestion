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

// question link -> https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
// function to find the maximum sum
pair<int,int> solve(Node* root)
{
    // Base case 
    if(root == NULL)
        return {0,0};
        
    // go to the left side of the root
    pair<int,int> left = solve(root->left);
    
    // go to the right side of the root
    pair<int,int> right = solve(root->right);
    
    // finally calculating the sum for the node itself;
    pair<int,int> node;
    
    // first part of the node is with including the node data;
    node.first = root->data + left.second + right.second;
    
    // second part of the node is with excluding the node data
    node.second = max(left.first, left.second) + max(right.first, right.second);
    
    // finally return to the above node.
    return node;
}

//Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root) 
{
    pair<int,int> ans = solve(root);
    
    return max(ans.first,ans.second);
}

int main()
{
    
    return 0;
}