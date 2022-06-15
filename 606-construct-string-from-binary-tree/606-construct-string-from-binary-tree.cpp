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
    void makeString(TreeNode* root,string &s)
    {
        if(root==NULL)
            return;
        s+=to_string(root->val);
        if(!root->left&&!root->right)
            return;
            s+="(";
            makeString(root->left,s);
            s+=")";
        if(root->right)
        {
            s+="(";
            makeString(root->right,s);
            s+=")";
        }
        
    }
    string tree2str(TreeNode* root) {
        string s;
        makeString(root,s);
        return s;
    }
};