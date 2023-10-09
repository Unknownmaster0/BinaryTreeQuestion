/*Question is to find the depth or height of the binary tree.*/
#include <iostream>
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

// Function to find the maximum depth of the binary tree.
/*Time complexity -> o(N) [har node ko 1 time visit kr rhe hai. And, total number of nodes is N.]
    Space complexity -> O(max height) [function call stack me kitna bar function call hua hai.]*/
int MaxHeight(Node *root)
{
    // when the root reaches to NULL, means the height is 0.
    if (root == NULL)
        return 0;

    // go to the left part of the tree.
    int left = MaxHeight(root->left);

    // go to the right part of the tree.
    int right = MaxHeight(root->right);

    // now need to find the height and return it.
    int ans = max(left, right) + 1;
    return ans;
}

// Function to find the minimum depth of the binary tree.
int MinHeight(Node *root)
{
    // when the root reaches to NULL, means the height is 0.
    if (root == NULL)
        return 0;

    // go to the left part of the tree.
    int left = MinHeight(root->left);

    // go to the right part of the tree.
    int right = MinHeight(root->right);

    //    Now in case of the minimum depth, there comes the two condition ->
    /*1. if one of left or right node having element and the other is NULL  or if the both the node is null.
        2. if the both the node is Not NULL.

        1 sol. -> if the situation comes, then find the max of the left and right part of the tree.
        2 sol. -> else find the min of the left and right part of the tree.*/

    // if the both node are not NULL, condition 2.
    if (root->left && root->right)
        return min(left, right) + 1;

    // in other cases , condition 1.
    else
        return max(left, right) + 1;
}

int main()
{
    Node *root = NULL;
    return 0;
}