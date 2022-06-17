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
    pair<int,int> height(TreeNode* root)
    {
        if(root==NULL)
            return make_pair(0,0);
        pair<int,int> p1,p2;
        p1=height(root->left);
        p2=height(root->right);
        int h=max(p1.first,p2.first)+1;
        int op1=p1.second;
        int op2=p2.second;
        int op3=p1.first+p2.first+1;
        return make_pair(h,max(p1.second,max(op1,max(op2,op3))));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return height(root).second-1;
    }
};