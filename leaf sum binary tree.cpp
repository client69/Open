#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
    
    public:
    Node(int key)
    {
        data=key;
        left=right=NULL;
    }
};

int leaf_traversal(Node *root)   // using preorder traveral
{
    if(root==NULL)
    {
        return 0;
    }
    int sum=0;
    if(root->left==NULL &&  root->right==NULL)
    {
        sum+= root->data;
    }
    
    return sum+leaf_traversal(root->left)+leaf_traversal(root->right);          
}



int main()
{
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    root->right->right->left=new Node(11);

    
   cout<<leaf_traversal(root)<<endl;
}



