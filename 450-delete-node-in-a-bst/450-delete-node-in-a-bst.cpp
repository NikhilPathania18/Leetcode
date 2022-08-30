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
    TreeNode* inorder(TreeNode* root)
    {
        while(root&&root->left)
            root=root->left;
        return root;
    }
    TreeNode *deleteNode(TreeNode* root,int key)
    {
        if(!root)   return NULL;
        if(key<root->val)
            root->left=deleteNode(root->left,key);
        else if(key>root->val)
            root->right=deleteNode(root->right,key);
        else
        {
            if(!root->left&&!root->right)   return NULL;
            if(root->left&&!root->right)    return root->left;
            if(root->right&&!root->left)    return root->right;
            TreeNode* temp=inorder(root->right);
            root->val=temp->val;
            root->right=deleteNode(root->right,temp->val);
        }
        return root;
    }
    
};