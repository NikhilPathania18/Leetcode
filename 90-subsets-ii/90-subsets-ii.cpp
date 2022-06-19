class Solution {
public:
    void sub(vector<int>& nums,int index, vector<int>& arr,set<vector<int>> &ans)
    {
        if(index==nums.size())
        {
            ans.insert(arr);
            return;
        }
        arr.push_back(nums[index]);
        sub(nums,index+1,arr,ans);
        arr.pop_back();
        sub(nums,index+1,arr,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> arr;
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        sub(nums,0,arr,ans);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};