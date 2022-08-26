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
    int getPathSum(TreeNode* root)
    {
        if(!root)   return 0;
        
        int leftSum=getPathSum(root->left);
        int rightSum=getPathSum(root->right);
        int sum=root->val+leftSum+rightSum;
        maxSum=max(maxSum,sum);
        // maxSum=max(maxSum,root->val+leftSum+rightSum);
        if(max(root->val+leftSum,max(root->val,root->val+rightSum))>maxSum)
            maxSum=max(root->val+leftSum,max(root->val,root->val+rightSum));
        
        return max(root->val,max(root->val+leftSum,root->val+rightSum));
    }
    int maxPathSum(TreeNode* root) {
        getPathSum(root);
        return maxSum;
    }
};