#include <iostream>
#include <vector>
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

void printVector(vector<int>v)
{
    for(int i = 0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

vector<int> zigZag(Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    q.push(root);

    bool LTR = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        cout << "the size of temp vector -> " << size << endl;

        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            cout << "frontNode -> " << frontNode->data << endl;
            q.pop();

            int index = LTR ? i : size - i - 1;
            cout << "index -> " << index << endl;
            temp[index] = frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
/* temp is fragmented and everytime a new temp is created and that temp is copied in ans
    example -> for first time -> temp = 1
                second time -> temp = 3 2
                third time -> temp = 4 5

                this way the program is executing. 
*/
        
        cout<<endl<<"Printing the temp vector"<<endl;
        printVector(temp);
        cout<<endl;

        LTR = !LTR;
        for(auto i:temp)
            ans.push_back(i);
    }
    return ans;
}



int main()
{
    Node *root = NULL;
    // data to build tree -> 1 2 -1 -1 3 4 -1 -1 5 -1 -1 
    root = buildTree(root);

    vector<int> final = zigZag(root);
    printVector(final);
    return 0;
}