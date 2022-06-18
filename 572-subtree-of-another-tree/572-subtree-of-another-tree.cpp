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
    bool checkIfEqual(TreeNode* root1,TreeNode* root2)
    {
        if(!root1&&!root2)
            return true;
        if((root1&&root2)&&root1->val==root2->val)
            return checkIfEqual(root1->left,root2->left)&&checkIfEqual(root1->right,root2->right);
        return false;
    }
    bool search(TreeNode* root,TreeNode* subRoot)
    {
        if(root==NULL&&subRoot==NULL)
            return true;
        if(root==NULL||subRoot==NULL)
            return false;
        if(root->val==subRoot->val)
            if(checkIfEqual(root,subRoot))
                return true;
        return search(root->left,subRoot)||search(root->right,subRoot);
            
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return search(root,subRoot);
    }
};