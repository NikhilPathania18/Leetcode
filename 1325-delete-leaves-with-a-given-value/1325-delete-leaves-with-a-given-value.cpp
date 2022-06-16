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
    bool flag=false;
    TreeNode* remove(TreeNode* root, int target) {
        if(root==NULL)
            return NULL;
        if(!root->left&&!root->right&&root->val==target)
        {
            
            flag=true;
            return NULL;
        }
        root->left=remove(root->left,target);
        root->right=remove(root->right,target);
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        root=remove(root,target);
        if(flag==true)
        {
            flag=false;
            root=removeLeafNodes(root,target);
        }
        return root;
    }
};