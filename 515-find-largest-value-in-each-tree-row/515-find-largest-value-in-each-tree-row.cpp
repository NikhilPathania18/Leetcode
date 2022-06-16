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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int> arr;
        queue<TreeNode*> q;
        q.push(root);
        int maxVal;
        while(!q.empty())
        {
            maxVal=q.front()->val;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                if(q.front()->val>maxVal)
                    maxVal=q.front()->val;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            arr.push_back(maxVal);
        }
        return arr;
    }
};