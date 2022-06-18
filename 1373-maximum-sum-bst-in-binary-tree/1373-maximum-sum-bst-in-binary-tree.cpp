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
    int maxSum=0;
    struct node
    {
        int sum=0;
        int minV=INT_MAX,maxV=INT_MIN;
    };
    node getSum(TreeNode* root)
    {
        node obj;
        if(root==NULL)
            return obj;
        
        node oL=getSum(root->left);
        node oR=getSum(root->right);
        
        if(root->val<=oL.maxV||root->val>=oR.minV)
        {
            obj.sum=0;
            obj.minV=INT_MIN;
            obj.maxV=INT_MAX;
            return obj;
        }
        int sum=root->val+oL.sum+oR.sum;
        maxSum=max(maxSum,sum);
        obj.sum=sum;
        obj.minV=min(root->val,oL.minV);
        obj.maxV=max(root->val,oR.maxV);
        return obj;
    }
    int maxSumBST(TreeNode* root) {
        getSum(root);
        return maxSum;
    }
};