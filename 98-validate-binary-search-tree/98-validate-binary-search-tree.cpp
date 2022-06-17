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
    bool isValid(TreeNode* root,TreeNode* l,TreeNode* r)
    {
        if(root==NULL)
            return true;
        if((l&&root->val<=l->val)||(r&&root->val>=r->val))
            return false;
        return isValid(root->left,l,root)&&isValid(root->right,root,r);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,NULL,NULL);
    }
};