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
    void inorder(TreeNode* root,vector<int>& arr)
    {
        if(root==NULL)  return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        
        map<int,int> ans;
        int maxl=0;
        for(int i=0;i<arr.size();i++)
        {
            ans[arr[i]]++;
            if(ans[arr[i]]>maxl)
                maxl=ans[arr[i]];
        }
        vector<int> result;
        for(auto i: ans)
            if(i.second==maxl)
                result.push_back(i.first);
        return result;
    }
};