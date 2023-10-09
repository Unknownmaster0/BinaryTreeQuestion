#include <iostream>
using namespace std;

/* Question link -> https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1 */

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

/*
   int height(Node *root)
   {
       if(root == NULL)
           return 0;

       int left = height(root->left);
       int right = height(root->right);

       return max(left,right) + 1;
   }
   */

// Naive approach
pair<bool, int> fast(Node *root)
{
    // when the root is null, then height must me 0 and the root must be the Balanced one.
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = fast(root->left);
    pair<bool, int> right = fast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool hght = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    // the second part is containing the height related information -> maximum depth.
    ans.second = max(left.second, right.second) + 1;
    if (leftAns && rightAns && hght)
        ans.first = true;
    else
        ans.first = false;

    return ans;
}

// Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{

    // optimal approach having time complexity -> O(n)
    return fast(root).first;

    // Brutforce approch having time complexity -> O(n^2)
    /*
    // Brutforce approach
    if(root == NULL)
        return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool hght = abs ( height(root->left) - height(root->right) ) <= 1;

    if(left && right && hght)
        return true;

    else
        return false;
    */
}

int main()
{

    return 0;
}