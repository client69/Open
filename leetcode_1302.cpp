class Solution {
public:
    
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(helper(root->left),helper(root->right));
    } 
    
    int help(TreeNode* root,int curr,int &maxh){
        if(root==NULL) return 0;
        if(curr==maxh) return root->val;
        return help(root->left,curr+1,maxh)+help(root->right,++curr,maxh);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int maxh=helper(root); 
        return help(root,1,maxh);
    }
};