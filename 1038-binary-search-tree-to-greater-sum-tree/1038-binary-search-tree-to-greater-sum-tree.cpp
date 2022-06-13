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
    int currSum=0;
    int sum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        sum(root->right);
        currSum+=root->val;
        root->val=currSum;
        sum(root->left);
        return currSum;
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL)
            return NULL;
        sum(root);
        return root;
        
    }
};