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
    int minDepth(TreeNode* root) {
        // if(root==NULL)
        //     return 0;
        // queue<TreeNode*> q;
        // int level=1;
        // q.push(root);
        // while(!q.empty())
        // {
        //     int size=q.size();
        //     for(int i=0;i<size;i++)
        //     {
        //         if(!q.front()->left&&!q.front()->right)
        //             return level;
        //         if(q.front()->left)
        //             q.push(q.front()->left);
        //         if(q.front()->right)
        //             q.push(q.front()->right);
        //         q.pop();
        //     }
        //     level++;
        // }
        // return level;
        
        if(root==NULL)
            return 0;
        
        if(!root->left && !root->right)
            return 1;
        
        int l,r;
        if(root->left)
         l = minDepth(root->left)+1;
        
        if(root->right)
         r = minDepth(root->right)+1;
        
        if(l<r) return l;
        else return r;
    }
};