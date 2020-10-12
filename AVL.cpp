#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left=nullptr;;
    Node* right=nullptr;
    int bal=0;
    int h=0;

    Node(int data){
        this->data=data;
    }
    Node(int b, int h){
        this->left=nullptr;
        this->right=nullptr;
        this->bal=b;
        this->h=h;
    }
};


void display(Node* root){
    if(root==nullptr) return;

    string s="";
    s+= root->left!=nullptr ? to_string(root->left->data)  : "."; 
    s+="<- " + to_string(root->data) + " ->";
    s+= root->right!=nullptr ? to_string(root->right->data)  : ".";

    cout<<s<<"\n";

    display(root->left);
    display(root->right); 
}

int getMax(Node* root){
        int ans=root->data;
        while(root->right!=nullptr){
            ans=root->right->data;
            root=root->right;
        }
        return ans;
}

void updateHeightAndBalance(Node* node){
    int lh=-1;
    int rh=-1;
    if(node->left!=nullptr)
        lh=node->left->h;

    if(node->right!=nullptr)
        rh=node->left->h;

    node->h=max(lh,rh)+1;
    node->bal=lh-rh;        
}

Node* rightRotation(Node* A){
    Node* B=A->left;
    Node* BKaRight=B->right;

    B->right=A;
    A->left=BKaRight;

    return B;
}

Node* leftRotation(Node* A){
    Node* B=A->right;
    Node* BkaLeft=B->left;

    B->left=A;
    A->right=BkaLeft;

    return B;
}

Node* rightLeftRotation(Node* A){
    Node* B=A->right;
    Node* C=B->left;

    Node* CkaLeft=C->left;
    
    C->left=B;
    B->left=CkaLeft;
    A->right=C;

    return leftRotation(A);
}

Node* leftRightRotation(Node* A){
    Node* B=A->left;
    Node* C=B->right;

    Node* CKaLeft=C->left;

    C->left=B;
    B->right=CKaLeft;
    A->left=C;

    return rightRotation(A);
}

Node* getRotation(Node* root){
    updateHeightAndBalance(root);

    if(root->bal==2){  //ll,lr  // root->bal<=2 if we are calculating height in terms of node;
        if(root->left->bal==1){
            return rightRotation(root);
        } else if(root->left->bal== -1){
            root->left=leftRotation(root->left);
            return rightRotation(root);
        }
    } else if(root->bal== -2){
        if(root->right->bal==1){
            root->right=rightRotation(root->right);
            return leftRotation(root);
        } else if(root->right->bal == -1){
            return leftRotation(root);
        }
    }
    return root;
}

Node* insert(Node* root, int val){
    if(root==nullptr) return new Node(val);

    if(val<root->data){
         root->left=insert(root->left,val);
    } else {
        root->right=insert(root->right,val);
    }

    root=getRotation(root);
    return root;
}

Node* deleteNode(Node *root, int val) //O(logn)
{
    if (root == nullptr)
        return nullptr;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else
    {

        if (root->left == nullptr || root->right == nullptr)
        {
            Node *node = root->left != nullptr ? root->left : root->right;
            delete root; // not for java.
            return node;
        }

        int mVal = getMax(root->left);
        root->data = mVal;
        root->left = deleteNode(root->left, mVal);
    }

    root = getRotation(root);
    return root;
}

void solve()
{
    Node *root = nullptr;
    for (int i = 1; i <= 14; i++)
        root = insert(root, i * 10);

    display(root);
}

int main(){
    return 0;
}