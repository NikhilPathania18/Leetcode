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
    int depth=0,sum=0;
    int deepestLeavesSum(TreeNode* root,int d=0) {
        if(root==NULL)
            return 0;
        if(!root->left&&!root->right)
        {
            if(d==depth)
            {
                sum+=root->val;
            }
            else if(d>depth)
            {
                sum=0;
                sum+=root->val;
                depth=d;
            }
        }
        deepestLeavesSum(root->left,d+1);
        deepestLeavesSum(root->right,d+1);
        return sum;
    }
};