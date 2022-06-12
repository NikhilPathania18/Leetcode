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
    vector<int> arr;
    void BST(TreeNode* root) {
        if(root==NULL)
            return ;
        BST(root->left);
        arr.push_back(root->val);
        BST(root->right);
    }
    bool isValidBST(TreeNode* root) {
        BST(root);
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i+1]<=arr[i])
                return false;
        }
        return true;
    }
};