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
    bool isSym(TreeNode* root1,TreeNode* root2)
    {
        if(!root1&&!root2)
            return true;
        else if((root1&&!root2)||(root2&&!root1))
            return false;
            
        if(root1->val!=root2->val)
            return false;
        if(!isSym(root1->left,root2->right))
            return false;
        if(!isSym(root1->right,root2->left))
            return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        if(isSym(root->left,root->right))
            return true;
        return false;
        
    }
    
};