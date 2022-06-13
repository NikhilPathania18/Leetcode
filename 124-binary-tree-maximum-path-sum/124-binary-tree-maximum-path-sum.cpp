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
    int maxSum=INT_MIN;
    int getSum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int l=getSum(root->left);
        int r=getSum(root->right);
        int sum=l+r+root->val;
        if(sum>maxSum)
            maxSum=sum;
        if(max(l+root->val,max(r+root->val,root->val))>maxSum)
            maxSum=max(l+root->val,max(r+root->val,root->val));
        return max(l+root->val,max(r+root->val,root->val));
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        getSum(root);
        return maxSum;
    }
};