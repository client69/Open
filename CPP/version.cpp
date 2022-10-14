#include<iostream>
#include<string.h>
#include<queue>
#include<cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
TreeNode* helper(vector<int> A, int a, int b)
{
    if(b >= a)
    {
        int mid = (b - a)/2;
        TreeNode* root = new TreeNode(A[mid]);
        root->left = helper(A, a, mid - 1);
        root->right = helper(A, mid + 1, b);
    }
    else
        return NULL;
}
 
 
TreeNode* sortedArrayToBST(vector<int> A) {
    return helper(A, 0, A.size() - 1);
}

int main()
{
    vector<int> v;
    v.push_back(1);
    // v.push_back(2);
    // v.push_back(2147483647);
    cout<<sortedArrayToBST(v);
    cout<<"1";
}