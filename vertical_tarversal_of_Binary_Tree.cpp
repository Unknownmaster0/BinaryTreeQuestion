#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

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

Node *buildTree(Node *root)
{
    int data;
    cout << "enter data: ";
    cin >> data;

    root = new Node(data);

    if (data == -1)
        return NULL;

    // left tree
    cout << "enter the data for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the data for right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraverse(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    cout << endl;
}

void printVector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

// explanation of this function is in copy notes.
vector<int> verticalTraversal(Node *root)
{
    vector<int> ans;

    if (root == NULL || root->data == -1)
        return ans;

    map<int, map<int, vector<int>>> nodes;

    queue<pair<Node *, pair<int, int>>> q;

    q.push(make_pair(root, make_pair(0, 0))); // b/c the level is 0 and the height is also 0.

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> p = q.front();
        q.pop();

        // taking out the Node, horizonatal distance, level. These values from the queue.
        Node *frontNode = p.first;
        int horizontalDistance = p.second.first;
        int level = p.second.second;

        // now store this value in the map
        nodes[horizontalDistance][level].push_back(frontNode->data);

        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(horizontalDistance - 1, level + 1))); // left jane pr horizontal dis decrease hoga and level always increase hoga
        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(horizontalDistance + 1, level + 1)));
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // data for build tree -> 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 7 -1 9 -1 -1
    levelOrderTraverse(root);
    vector<int> ans = verticalTraversal(root);

    printVector(ans);
    return 0;
}
