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
    int maxDepth=-1;
    void preorder(TreeNode* root,vector<vector<int>>& ans,int depth)
    {
        if(root==NULL)
            return;
        if(depth>maxDepth)
        {
            ans.push_back({root->val});
            maxDepth++;
        }
        else
        {
            ans[depth].push_back(root->val);
        }
        preorder(root->left,ans,depth+1);
        preorder(root->right,ans,depth+1);
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        preorder(root,ans,0);
        return ans;
    }
};