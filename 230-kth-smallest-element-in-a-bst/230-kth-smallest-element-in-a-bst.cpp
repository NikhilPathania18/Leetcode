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
    int i=0;
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
            return INT_MIN;
        int l=kthSmallest(root->left,k);
        
            i++;
            if(i==k)
            return root->val;
        
        
        int r=kthSmallest(root->right,k);
        if(l!=INT_MIN)
            return l;
        if(r!=INT_MIN)
            return r;
        return INT_MIN;
    }
};