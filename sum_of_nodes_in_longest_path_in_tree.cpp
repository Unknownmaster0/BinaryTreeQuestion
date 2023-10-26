#include<iostream>
#include<bits/stdc++.h>
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

void maximumSum(Node* root, int sum, int &maxSum, int len,int &maxLen)
{
    if(root == NULL)
    {
        if(len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }

        else if(len == maxLen)
            maxSum = max(maxSum, sum);
    }

    // collect the sum -> 
    sum += root->data;
    // call for the left and right part
    maximumSum(root->left, sum , maxSum, len, maxLen);
    maximumSum(root->right, sum , maxSum, len, maxLen);

}


// question link -> https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
int sumOfLongestPath(Node* root)
{
    int sum = 0, maxSum = INT_MIN;
    int length = 0, maxLength = -1;

    maximumSum(root,sum,maxSum,length,maxLength);

    return maxSum;
}

int main()
{
    
    return 0;
}