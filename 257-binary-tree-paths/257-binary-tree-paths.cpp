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
    vector<string> arr;
    void path(TreeNode* root,string s)
    {
        if(root==NULL)
            return;
        s.append("->");
        s+=to_string(root->val);
        if(!root->left&&!root->right)
        {
            arr.push_back(s);
        }
        path(root->left,s);
        path(root->right,s);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        s+=to_string(root->val);
        if(!root->left&!root->right)
            arr.push_back(s);
        path(root->left,s);
        path(root->right,s);
        return arr;
    }
};