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
//     int count=0;
//     void bst(TreeNode* root,int sum)
//     {
//         if(root==NULL)
//             return;
//         sum-=root->val;
//         if(sum==0)
//             count++;
//         bst(root->left,sum);
//         bst(root->right,sum);
        
//     }
//     void bst2(TreeNode* root,int sum)
//     {
//         if(root==NULL)
//             return ;
//         bst(root,sum);
//         bst(root->left,sum);
//         bst(root->right,sum);
//     }
//     int pathSum(TreeNode* root, int targetSum) {
//         if(root==NULL)
//             return 0;
        
//         bst2(root,targetSum);
//         return count;
//     }
    int ans;
    void solve(TreeNode* root,  unsigned long long sum){
           if(root==NULL){
                   return;
           }
           sum-=root->val;
           if(sum==0){
                   ans++;
           }
           solve(root->left,sum);
           solve(root->right,sum);
    }
    void helper(TreeNode* root, unsigned long long sum){
           
            solve(root,sum);
            if(root->left){
                     helper(root->left,sum);
            }
            if(root->right){
                    helper(root->right,sum);
            }
    }
    int pathSum(TreeNode* root, int targetSum) {
            ans=0;
            if(root==NULL){
                    return 0;
            }
            unsigned long long sum=targetSum;
            helper(root,sum);
            return ans;
            
        
    }
};


