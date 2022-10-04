//inorder of the bst tree is always a sorted array

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *formBST(Node *root, int val)
{

    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = formBST(root->left, val);
    }
    else
    {
        root->right = formBST(root->right, val);
    }
    return root;
}
int main()
{
    Node *root = NULL;
    root = formBST(root, 5);
    formBST(root, 1);
    formBST(root, 3);
    formBST(root, 4);
    formBST(root, 2);
    formBST(root, 7);

    return 0;
}