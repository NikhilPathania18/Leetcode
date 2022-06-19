class Solution {
public:
    void sub(vector<int>& nums,int index,vector<int>& arr,vector<vector<int>> &ans)
    {
        if(index==nums.size())
        {
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[index]);
        sub(nums,index+1,arr,ans);
        arr.pop_back();
        sub(nums,index+1,arr,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        vector<vector<int>> ans;
        sub(nums,0,arr,ans);
        return ans;
    }
};
