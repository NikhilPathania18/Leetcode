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
    unordered_map<int,int> m;
    int solve(TreeNode* root)
    {
        int l=0,r=0;
        if(root->left)
            l=solve(root->left);
        if(root->right)
            r=solve(root->right);
        m[l+r+root->val]++;
        return l+r+root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        
        vector<int> ans;
        int currMax=INT_MIN;
        for(auto i: m)
        {
            if(i.second>currMax)
            {
                ans.clear();
                ans.push_back(i.first);
                currMax=i.second;
            }
            else if(i.second==currMax)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};