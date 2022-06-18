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
        {
            return obj;
        }
        node oL=getSum(root->left);
        node oR=getSum(root->right);
        
        if(root->val<=oL.maxV||root->val>=oR.minV)
        {
            obj.sum=0;
            obj.minV=INT_MIN;
            obj.maxV=INT_MAX;
            return obj;
        }
        
        int sum=oL.sum+oR.sum+root->val;
        maxSum=max(maxSum,sum);
        
        obj.sum=sum;
        obj.minV=min(oL.minV,root->val);
        obj.maxV=max(oR.maxV,root->val);
        return obj;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    node sumFunc(TreeNode* root)
    {
        node obj;
        if(root==NULL)
        {
            return obj;
        }
        node objLeft=sumFunc(root->left);
        node objRight=sumFunc(root->right);
        if(root->val<=objLeft.maxV||root->val>=objRight.minV)
        {
            cout<<root->val;
            obj.minV=objLeft.maxV;
            obj.maxV=objRight.minV;
            return obj;
        }
        maxSum=max(maxSum,objLeft.sum+objRight.sum+root->val);
        // cout<<objLeft.sum+objRight.sum+root->val<<"\n";
        obj.sum=objLeft.sum+objRight.sum+root->val;
        obj.minV=min(objLeft.minV,root->val);
        obj.maxV=max(objRight.maxV,root->val);
        return obj;
    }
    
    int maxSumBST(TreeNode* root) {
        getSum(root);
        return maxSum;
    }
};