#include<iostream>
#include<map>
using namespace std;

// question link -> https://practice.geeksforgeeks.org/problems/k-sum-paths/1

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

int mod = 1e9+7;
// gives tle this function
/*
void numbersPaths(Node*root, int k, int& count, vector<int>& path)
{
    // base case
    if(root == NULL)
        return;
        
    // first push the root element or add the current node to the path
    path.push_back(root->data);
    

    // left call
    numbersPaths(root->left, k, count, path);
    // right call
    numbersPaths(root->right, k, count, path);
    
    // check for the sum in the vector path
    int size = path.size();
    int sum = 0;
    for(int i = size-1; i>=0; i--)
    {
        sum += path[i];
        
        if(sum == k)
        {
            count ++;
            count %= mod;
        }
    }
    
    // backtracking steps -> we need to pop the element of the current root
    path.pop_back();
}

*/

// optimal approach -> Nice use of the mapping technique.
// Time complexity -> O(Number of nodes) and the space complexity -> O(number of nodes or height of tree)
int numbersPaths(Node* root, int k, map<int,int>& path, int sum)
{
    // base case 
    if(root == NULL)
        return 0;
        
    int count = 0;
    
    // increment the sum
    sum += root->data;
    
    // if the sum-k is present in the mapping then, increment the count
    if(path.find(sum-k) != path.end())
        count += path[sum-k];
        
    // update the mapping of the current sum
    path[sum]++;
        
    int leftCount = numbersPaths(root->left, k, path, sum);
    int rightCount = numbersPaths(root->right, k , path, sum);
    
    // backtracking step -> decrement the frequency of the current sum
    path[sum]--;
    
    // finally return the value for the above node
    return count + leftCount + rightCount;
}

int sumK(Node *root,int k)
{
    map<int,int> path;
    path[0]++;
    return numbersPaths(root,k,path,0);
}

int main()
{
    
    return 0;
}