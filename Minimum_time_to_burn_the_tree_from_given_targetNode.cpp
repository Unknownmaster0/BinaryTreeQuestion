#include<iostream>
#include<map>
#include<queue>
using namespace std;

// question link -> https://practice.geeksforgeeks.org/problems/burning-tree/1

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


Node* createMapping(Node* root, int target, map<Node*, Node*> &mp)
{
    Node* targetNode = NULL;
    
    // we do level order traersal
    queue<Node*> q;
    q.push(root);
    // initially initialise that the Parent of the root node is NULL.
    mp[root] = NULL;
    
    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();
        
        if(front -> data == target)
            targetNode = front;
            
        if(front -> left)
        {
            q.push(front->left);
            mp[front->left] = front;
        }
        
        if(front -> right)
        {
            q.push(front->right);
            mp[front->right] = front;
        }
    }
    
    return targetNode;
}


int burnTree(Node* root, map<Node*, Node*> mp)
{
    int timeToBurn = 0;
    
    // visited mapping
    map<Node*, bool> visited;
    
    // burning queue
    queue<Node*> q;
    q.push(root);
    
    visited[root] = true;
    
    while(!q.empty())
    {
        int size = q.size();
        bool burned = 0;
        
        // now burning the left right and parent of the nodes that are in the queue.
        for(int i = 0; i<size; i++)
        {
            Node* front = q.front();
            q.pop();
            
            if(front -> left && !visited[front->left])
            {
                burned = 1;
                // burning step -> when the Node is push into the queue it is burned.
                q.push(front->left);
                visited[front->left] = 1;
            }
            
            if(front -> right && !visited[front->right])
            {
                burned = 1;
                // burning step -> when the Node is push into the queue it is burned.
                q.push(front->right);
                visited[front->right] = 1;
            }
            
            // step for the parent of the node.
            if(mp[front] && !visited[mp[front]])
            {
                burned = 1;
                // burning step -> when the Node is push into the queue it is burned.
                q.push(mp[front]);
                visited[mp[front]] = 1;
            }
        }
        
        if(burned)
            timeToBurn ++;
    }
    
    return timeToBurn;
}


int minTime(Node* root, int target) 
{
    // Time complexity of this solution -> O(Number of nodes) + O(Number of nodes)
    // space complexity -> O(Number of nodes) + O(Number of nodes)
    /*
    we have three steps to solve this question -> 
    
    1. create the node to parent mapping.
    2. traverse and reach the target Node.
    3. finally burn the tree. -> In this function we need two data structure (map, queue)
            map -> required for mark the node as visited or not.
            queue -> for burning the node.
    */
    
    map< Node*, Node* > nodeToParent;
    
    Node* targetNode = createMapping(root, target, nodeToParent);
    
    return burnTree(targetNode, nodeToParent);
}

int main()
{
    
    return 0;
}