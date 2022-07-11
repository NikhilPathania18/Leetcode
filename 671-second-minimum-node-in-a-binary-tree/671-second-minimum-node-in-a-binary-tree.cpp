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
    int min1=-1,min2=-1;
    
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        if(min1==-1||root->val<min1)
        {
            min2=min1;
            min1=root->val;
        }
        else if(min2==-1||root->val<min2)
        {
            if(root->val!=min1)
                min2=root->val;
        }
        
        inorder(root->left);
        inorder(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        inorder(root);
        return min2;
    }
};