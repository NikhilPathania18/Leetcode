class Solution {
public:
    vector<vector<int>> ans;
    void sub(vector<int>& nums,int index,vector<int>& arr)
    {
        if(index==nums.size())
        {
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[index]);
        sub(nums,index+1,arr);
        arr.pop_back();
        sub(nums,index+1,arr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        sub(nums,0,arr);
        return ans;
    }
};
