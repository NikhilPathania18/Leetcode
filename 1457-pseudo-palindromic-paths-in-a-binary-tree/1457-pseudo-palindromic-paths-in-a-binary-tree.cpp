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
    int count=0;
    bool isPalindrome(map<int,int> &m)
    {
        bool flag=false;
        for(auto i: m)
        {
            if(i.second%2==1)
            {
                if(flag)    return false;
                flag=true;
            }
        }
        return true;
    }
    void countPalindromes(TreeNode* root,map<int,int> &m)
    {
        if(!root)   return ;
        m[root->val]++;
        if(!root->left&&!root->right)
        {
            if(isPalindrome(m)) count++;
        }
        countPalindromes(root->left,m);
        countPalindromes(root->right,m);
        m[root->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int> m;
        countPalindromes(root,m);
        return count;
    }
};