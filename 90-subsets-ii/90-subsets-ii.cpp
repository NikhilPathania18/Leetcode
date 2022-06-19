class Solution {
public:
    void sub(vector<int>& nums,int index, vector<int>& arr,vector<vector<int>> &ans)
    {
        ans.push_back(arr);
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index&&nums[i]==nums[i-1])
                continue;
            arr.push_back(nums[i]);
            sub(nums,i+1,arr,ans);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> arr;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        sub(nums,0,arr,ans);
        return ans;
    }
};