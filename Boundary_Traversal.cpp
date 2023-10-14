#include <iostream>
#include <vector>
using namespace std;

/*Question link -> https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1 */

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void traverseLeft(Node *root, vector<int> &ans)
{
    // if root is null or the root is leaf node then don't push.
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;

    ans.push_back(root->data);

    if (root->left)
        traverseLeft(root->left, ans);
    // if the root->left is null , then traverse to right portion.
    else
        traverseLeft(root->right, ans);
}

// we have to push all the leaf node of the tree.
void traverseLeaf(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    // root ke left part ka sara leaf Node.
    traverseLeaf(root->left, ans);
    // root ke right part ka sara leaf Node.
    traverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{
    // if root is null or the root is leaf node then don't push.
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;

    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    // isme wapas jate samay(from the recursion call) push_back krna hota hai a/c to approach.
    ans.push_back(root->data);
}

vector<int> boundary(Node *root)
{
    vector<int> ans;

    ans.push_back(root->data);

    // pushing the left boundary of the tree.
    traverseLeft(root->left, ans);

    // pushing the leaf Node of the left part of the tree.
    traverseLeaf(root->left, ans);
    // pushing the leaf Node of the right part of the tree.
    traverseLeaf(root->right, ans);

    // pushing the right boundary of the tree.
    traverseRight(root->right, ans);

    return ans;
}

int main()
{

    return 0;
}