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
    int eval(TreeNode* root)
    {
        if(!root)   return -1;
        
        int l=eval(root->left);
        int r=eval(root->right);
        
        if(l==-1||r==-1)   return root->val;
        
        if(root->val==2)
        {
            if(l==0&&r==0)  return 0;
            else return 1;
        }
        if(root->val==3)
        {
            if(l==1&&r==1)  return 1;
            else return 0;
        }
        return 0;
    }
    bool evaluateTree(TreeNode* root) {
        return eval(root);
    }
};