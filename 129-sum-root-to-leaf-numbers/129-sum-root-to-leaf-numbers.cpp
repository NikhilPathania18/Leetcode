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
    int convertToInt(string s)
    {
        int j=s.size()-1;
        int num=0;
        while(j>=0)
        {
            num+=(s[j]-48)*pow(10,s.size()-j-1);
            j--;
        }
        return num;
    }
    int findSum(TreeNode* root,string num)
    {
        if(root==NULL)
            return 0;
        num+=to_string(root->val);
        if(!root->left&&!root->right)
        {
            sum+=convertToInt(num);
        }
        findSum(root->left,num);
        findSum(root->right,num);
        return root->val;
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        string s;
        findSum(root,s);
        return sum;
    }
};