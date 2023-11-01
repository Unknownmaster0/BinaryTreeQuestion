#include<iostream>
#include<unordered_map>
using namespace std;

// question link -> https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
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

// function having the time complexity -> O(N)
// pass the map and postIndex with the refrence wise.
Node* TreeBuild(int in[], int post[], int &PostIndex, int inStart, int inEnd, int n, unordered_map<int,int> &mapping)
{
    if(PostIndex < 0 || inStart > inEnd)
        return NULL;
        
    int element = post[PostIndex--];
    Node* root = new Node(element);
    
    // find the position of the element in the inorder array.
    int pos = mapping[element];
    
    root->right = TreeBuild(in, post, PostIndex, pos+1, inEnd, n , mapping);
    root->left = TreeBuild(in, post, PostIndex, inStart, pos -1, n , mapping);
    
    return root;
}

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    // using the mapping for reducing the time complexity.
    
    unordered_map<int,int> mapping;
    
    // mapping done.
    for(int i = 0; i<n; i++)
        mapping[in[i]] = i;
        
        
    int postIndex = n-1;
    return TreeBuild(in, post, postIndex, 0, n-1, n, mapping);
    
}


int main()
{
    
    return 0;
}