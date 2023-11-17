#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            left = NULL;
            right = NULL;
        }
};

//Function to convert binary tree into circular doubly linked list.
Node *bTreeToCList(Node *root,Node* &prev, Node* &head)
{
    /* For making the binary tree to the doubly linked list -> 
    we have to use the two variable pointer (prev , head) 
    
    As we have to follow the inorder traversal -> (Left, Node, right)
    
    so make the left call first.
    then process the root/Node part
    then make the right call.
    
    when traverses all the left node, till the last one become NULL,
    then we make the pointer left and right with the root node to the prev node in the doubly linked list.
    
    But in case of the Circular doubly linked list -> we just need to add the one extra thing, the right 
    part also.
    same thing will be done with the right part to maintain the circularity.
    */
    
    if(root == NULL) return NULL;
    
    bTreeToCList(root->left,prev,head);
    
    // till here we process all the left part, now make the head node 
    if(prev == NULL)
        head = root;
        
    else{
        root->left = prev;
        prev->right = root;
    }
    
    // Now update the prev;
    prev = root;
    
    // make the right call
    bTreeToCList(root->right,prev,head);
    
    // now make the changes to the pointer to maintain the circularity.
    prev -> right = head;
    head -> left = prev;
    
    return head;
}

Node* convertTree(Node* root){

    Node* prev = NULL;
    Node* head = NULL;

    return bTreeToCList(root,prev,head);
}

// check the print function of this it may be improved.
void print(Node* root)
{
    Node* temp = root;
    cout<<temp->data<<" ";
    temp = temp -> right;
    while(temp != root)
    {
        cout<<temp->data<<" ";
        temp = temp -> right;
    }
    cout<<endl;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root = convertTree(root);
    print(root);
    return 0;
}