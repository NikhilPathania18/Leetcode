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
    void inorder(TreeNode* root,vector<int> &arr)
    {
        if(root==NULL)
            return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> arr;
        if(arr.size()==1)
            return false;
        inorder(root,arr);
        for(int i=0;i<arr.size();i++)
        {
            int diff=k-arr[i];
            int start=0,end=arr.size()-1;
            while(start<=end)
            {
                int mid=(start+end)/2;
                if(arr[mid]==diff&&diff!=arr[i])
                    return true;
                if(diff<arr[mid])
                {
                    end=mid-1;
                }
                else
                    start=mid+1;
            }
        }
        return false;
    }
};