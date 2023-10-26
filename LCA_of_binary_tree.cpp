#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Time complexity -> O(N) ; Space complexity -> O(N) 
/*
// this is the approach to store the path of the both the targets and then check for the last common element.

// utility function to store the path of the target, if present in the tree.
bool findPath(TreeNode* root, int target, vector<int>& path) {
    if (root == nullptr)
        return false;

    path.push_back(root->val);

    if (root->val == target)
        return true;

    if (findPath(root->left, target, path) || findPath(root->right, target, path))
        return true;

    path.pop_back();
    return false;
}

// function to return the lca of the targets.
int findLowestCommonAncestor(TreeNode* root, int n1, int n2) {
    vector<int> path1, path2;

    if (!findPath(root, n1, path1) || !findPath(root, n2, path2)) {
        // If either n1 or n2 is not present in the tree, there is no LCA.
        return -1;
    }

    int lca = -1;
    for (int i = 0; i < min(path1.size(), path2.size()); i++) {
        if (path1[i] == path2[i]) {
            lca = path1[i];
        } else {
            break;
        }
    }

    return lca;
}
*/


// Time complexity -> O(N) ; Space complexity -> O(1) constant space;
int findLowestCommonAncestor(TreeNode* root, int n1, int n2)
{
    if(root == NULL)
        return 0;

    if(root->data == n1 || root->data == n2)
        return root->data;

    int leftAns = findLowestCommonAncestor(root->left, n1,n2);
    int rightAns = findLowestCommonAncestor(root->right, n1,n2);

    if(leftAns == 0)
    {
        if(rightAns == 0)
            return 0;
        else 
            return rightAns;
    }
    else 
    {
        if(rightAns == 0)
            return leftAns;

        return root->data;
    }
    
}


int main() {
    // Create a sample binary tree.
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    int n1 = 5, n2 = 4;

    int lca = findLowestCommonAncestor(root, n1, n2);

    if (lca != -1) {
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is " << lca << endl;
    } else {
        cout << "No common ancestor found. One or both nodes are not present in the tree." << endl;
    }

    return 0;
}
