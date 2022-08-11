/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root,TreeNode* l=NULL,TreeNode* r=NULL) {
        if(!root)   return true;
        if((l&&root->val<=l->val)||(r&&root->val>=r->val))
            return false;
        bool op1=isValidBST(root->left,l,root);
        bool op2=isValidBST(root->right,root,r);
        return op1&&op2;
    }
};