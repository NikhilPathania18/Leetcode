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
    
    TreeNode* BST(vector<int>& arr,int l,int r)
    {
        if(l>r)
            return NULL;
        int big=arr[l];
        int index=l;
        for(int i=l;i<=r;i++)
        {
            if(arr[i]>big)
            {
                big=arr[i];
                index=i;
            }
        }
        TreeNode* node=new TreeNode(big);
        node->left=BST(arr,l,index-1);
        node->right=BST(arr,index+1,r);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return BST(nums,0,nums.size()-1);
    }
};