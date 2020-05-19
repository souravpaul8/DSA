//https://leetcode.com/problems/symmetric-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isSym(root->left,root->right);
    }
    
    bool isSym(TreeNode *l,TreeNode *r){
        if(!l && !r)
            return true;
         if(!l || !r)
            return false;
        if(l->val != r->val)
            return false;
        return isSym(l->left,r->right) && isSym(l->right,r->left);
    }
};