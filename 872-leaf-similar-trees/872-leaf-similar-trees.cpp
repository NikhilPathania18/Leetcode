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
    void insert(TreeNode* root,vector<int> &arr)
    {
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL)
            arr.push_back(root->val);
        insert(root->left,arr);
        insert(root->right,arr);
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1,arr2;
        insert(root1,arr1);
        insert(root2,arr2);
        if(arr1==arr2)
            return true;
        return false;
    }
};