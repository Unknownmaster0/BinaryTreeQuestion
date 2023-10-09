#include <iostream>
using namespace std;

// Question link -> https://practice.geeksforgeeks.org/problems/sum-tree/1

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

pair<bool, int> isSumTreeFast(Node *root)
{
    // Base cases
    if (root == NULL)
        return {true, 0};

    // here leaf node condition, return true, if leaf node. and return the value of the node.
    if (root->left == NULL && root->right == NULL)
        return {true, root->data};

    // Now calling the left and right subtree using recursion
    pair<bool, int> left = isSumTreeFast(root->left);
    pair<bool, int> right = isSumTreeFast(root->right);

    // checking if the left and right is sum Tree or not.
    bool leftSum = left.first;
    bool rightSum = right.first;

    // Now calculating the sum of the left and right part of the subtree and checking with the root
    bool condn = (root->data == left.second + right.second);

    pair<bool, int> ans;

    // storing the sum of the left and right part of the subtree.
    ans.second = root->data + left.second + right.second;

    if (leftSum && rightSum && condn)
        ans.first = true;

    else
        ans.first = false;

    return ans;
}

bool isSumTree(Node *root)
{
    return isSumTreeFast(root).first;
}

int main()
{

    return 0;
}