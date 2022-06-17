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
    int sum=0;
    int convert(string s)
    {
        if(s.length()==0)
            return 0;
        int num=0;
        for(int j=s.size()-1;j>=0;j--)
        {
            num+=((s[j])-48)*pow(2,s.size()-j-1);
        }
        return num;
    }
    void r2l(TreeNode* root,string s)
    {
        if(root==NULL)
            return;
        s+=to_string(root->val);
        if(!root->left&&!root->right)
        {
            sum+=convert(s);
            return;
        }
        r2l(root->left,s);
        r2l(root->right,s);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL)
            return 0;
        r2l(root,"");
        return sum;
    }
};