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

// Time complexity -> O(n)
// Function to check if two trees are identical.
bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;

    if (r1 == NULL && r2 != NULL)
        return false;
    if (r1 != NULL && r2 == NULL)
        return false;

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool check = (r1->data == r2->data);

    if (left && right && check)
        return true;

    else
        return false;
}

int main()
{

    return 0;
}