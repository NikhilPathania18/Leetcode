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
    vector<int> rightView(vector<int>& ans,TreeNode* root,int currLevel,int &maxLevel)
    {
        if(root==NULL)
            return {};
        if(currLevel>maxLevel)
        {
            ans.push_back(root->val);
            maxLevel=currLevel;
        }
        rightView(ans,root->right,currLevel+1,maxLevel);
        rightView(ans,root->left,currLevel+1,maxLevel);
        return ans;
        
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int> ans;
        int maxLevel=0;
        return rightView(ans,root,1,maxLevel);
        
        
        // queue<TreeNode*> q;
        // q.push(root);
        // vector<int> arr;
        // TreeNode* temp;
        // int size;
        // while(!q.empty())
        // {
        //     size=q.size();
        //     temp=q.front();
        //     arr.push_back(temp->val);
        //     for(int i=0;i<size;i++)
        //     {
        //         if(q.front()->right)
        //             q.push(q.front()->right);
        //         if(q.front()->left)
        //             q.push(q.front()->left);
        //         q.pop();
        //     }
        // }
        // return arr;
    }
};