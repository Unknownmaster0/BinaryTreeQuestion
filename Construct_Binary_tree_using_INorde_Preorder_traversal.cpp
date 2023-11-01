#include<iostream>
using namespace std;

// question link -> https://practice.geeksforgeeks.org/problems/construct-tree-1/1

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

int findPosition(int in[], int data, int start, int end)
{
    for(int i = start; i<=end; i++)
    {
        if(in[i] == data)
            return i;
    }
    
    return -1;        
}

// Time complexity of this function is -> O(N * N) -> as for every iteration we are also calling the 
//                                                      findPosition func having O(N) time complexity.

// we need to retain the value of the 'indexPre'.
Node* treeBuild(int in[], int pre[], int &indexPre, int startIn, int endIn, int n)
{
    // base case ->  when the preOrder index will go out of bound  OR  
    //if the startIndex of inorder is greater than endIndex of inorder.
    if( (indexPre >= n) || (startIn > endIn) )
        return NULL;
        
    // take out element of the preOrder array.
    int value = pre[indexPre++]; // also incremnt the index
    
    // creating the node of data = data;
    Node* root = new Node(value);
    
    // find the data in the inOrder array . 
    int pos = findPosition(in, value, startIn, endIn);
    
    
    // make the recursive calls for left part.
    // for the left part -> the inOrder index will become from (start , pos -1) b/c the pos is the index of the root->data element.
    root->left = treeBuild(in, pre, indexPre, startIn, pos-1,n);
    
    // similarly make the right call
    root->right = treeBuild(in, pre, indexPre, pos + 1, endIn,n);
    
    return root;
}

//lecture 66 -> 
Node* buildTree(int in[],int pre[], int n)
{
    // 0 -> first index of the preOrder array.
    // 0 -> first index of the inOrder array.
    // n-1 -> end index of the inOrder array.
    // n -> size of the preOrder array.
    
    int preIndex = 0;
    return treeBuild(in, pre, preIndex, 0, n-1, n);
    
}


void postOrder(Node* root)
{
    if(root == NULL)
        return ;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    int inorder[] = {3,1,4,0,5,2};
    int preorder[] = {0,1,3,4,2,5};

    int size = 6;

    Node* root = buildTree(inorder, preorder, size);

    postOrder(root);

    cout<<endl;

    return 0;
}