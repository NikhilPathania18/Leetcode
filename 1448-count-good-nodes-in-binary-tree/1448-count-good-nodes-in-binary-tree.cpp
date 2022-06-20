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
    int count=0;
public:
    void countNodes(TreeNode* root,int maxValue)
    {
        if(root==NULL)
            return;
        if(maxValue<=root->val)
            count++;
        maxValue=max(root->val,maxValue);
        countNodes(root->left,maxValue);
        countNodes(root->right,maxValue);
    }
    int goodNodes(TreeNode* root) {
        countNodes(root,root->val);
        return count;
    }
};