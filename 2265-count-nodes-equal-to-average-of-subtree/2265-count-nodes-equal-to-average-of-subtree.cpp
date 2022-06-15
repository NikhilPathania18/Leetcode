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
    int noOfNodes=0;
    int ans=0;
    int avg;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        sum+=root->val;
        noOfNodes++;
        inorder(root->right);
    }
    int getAvg(TreeNode* root)
    {
        sum=0;
        noOfNodes=0;
        inorder(root);
        avg=sum/noOfNodes;
        return avg;
    }
    int averageOfSubtree(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        if(root->val==getAvg(root))
            ans++;
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return ans;
    }
};