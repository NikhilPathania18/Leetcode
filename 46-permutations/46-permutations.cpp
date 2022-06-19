class Solution {
public:
//     void perm(vector<int>& nums,vector<int>& arr,int index,vector<bool> &isTaken,vector<vector<int>> &ans)
//     {
//         if(arr.size()==nums.size())
//         {
//             ans.push_back(arr);
//             return;
//         }
        
//         for(int j=0;j<nums.size();j++)
//             {
//                 if(isTaken[j])
//                     continue;
                
//                 arr.push_back(nums[j]);
//                 isTaken[j]=true;
//                 perm(nums,arr,j+1,isTaken,ans);
//                 isTaken[j]=false;
//                 arr.pop_back();
//             }
//     }
    
    void perm2(vector<int>& nums,int index,vector<vector<int>> &ans)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            perm2(nums,index+1,ans);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> arr;
        vector<vector<int>> ans;
        vector<bool> isTaken(nums.size(),false);
        // perm(nums,arr,0,isTaken,ans);
        perm2(nums,0,ans);
        return ans;
    }
};