class Solution {
public:
    void solve(vector<int>& nums,int index,vector<bool>& isTaken,set<vector<int>>& ans,vector<int>& arr)
    {
        if(index==nums.size())
        {
            ans.insert(arr);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(isTaken[i])  continue;
            arr.push_back(nums[i]);
            isTaken[i]=true;
            solve(nums,index+1,isTaken,ans,arr);
            isTaken[i]=false;
            arr.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> isTaken(nums.size(),false);
        set<vector<int>> ans;
        vector<int> arr;
        sort(nums.begin(),nums.end());
        solve(nums,0,isTaken,ans,arr);
        vector<vector<int>> result;
        for(auto i: ans)
        {
            result.push_back(i);
        }
        return result;
    }
};