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
    vector<vector<int>> arr;
    int tSum;
    void sumLeaf(TreeNode* root,vector<int> &values,int sum)
    {
        if(root==NULL)
            return ;
        if(!root->left&&!root->right&&sum==root->val)
        {
            values.push_back(root->val);
            arr.push_back(values);
            values.pop_back();
        }
        values.push_back(root->val);
        sumLeaf(root->left,values,sum-root->val);
        sumLeaf(root->right,values,sum-root->val);
        values.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return {};
        vector<int> inner;
        sumLeaf(root,inner,targetSum);
        return arr;
    }
};