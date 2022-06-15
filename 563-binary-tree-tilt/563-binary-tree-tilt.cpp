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
    int sum=0;
    int getSum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return (getSum(root->left)+getSum(root->right)+root->val);
    }
    void makeTilt(TreeNode* root) {
        if(root==NULL)
            return;
        root->val=abs(getSum(root->left)-getSum(root->right));
        sum+=root->val;
        makeTilt(root->left);
        makeTilt(root->right);
    }
    int findTilt(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        makeTilt(root);
        return sum;
    }
};