class Solution {
public:
    set<vector<int>> ans;
    void sub(vector<int>& nums,int index, vector<int>& arr)
    {
        if(index==nums.size())
        {
            ans.insert(arr);
            return;
        }
        arr.push_back(nums[index]);
        sub(nums,index+1,arr);
        arr.pop_back();
        sub(nums,index+1,arr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> arr;
        sort(nums.begin(),nums.end());
        sub(nums,0,arr);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};