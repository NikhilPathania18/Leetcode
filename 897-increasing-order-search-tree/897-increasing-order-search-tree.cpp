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
    vector<TreeNode*> arr;
    TreeNode* head=NULL;
    void bt(TreeNode* root)
    {
        if(root==NULL)
            return ;
        bt(root->left);
        arr.push_back(root);
        bt(root->right);
    }
    void create()
    {
        for(int i=0;i<arr.size()-1;i++)
        {
            arr[i]->left=NULL;
            arr[i]->right=arr[i+1];
        }
        arr[arr.size()-1]->left=arr[arr.size()-1]->right=NULL;
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL)
            return NULL;
        bt(root);
        create();
        return arr[0];
    }
};