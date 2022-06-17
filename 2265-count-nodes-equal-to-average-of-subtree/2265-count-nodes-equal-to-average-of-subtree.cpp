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
    int noOfNodes=0;
    pair<int,int> average(TreeNode* root)
    {
        if(root==NULL)
            return make_pair(0,0);
        int sum=0;
        pair<int,int> p1,p2;
        p1=average(root->left);
        p2=average(root->right);
        sum=root->val+p1.first+p2.first;
        int nodes=0;
        nodes=1+p1.second+p2.second;
        if(sum/nodes==root->val)
            noOfNodes++;
        return make_pair(sum,nodes);
    }
    int averageOfSubtree(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        average(root);
        return noOfNodes;
    }
};