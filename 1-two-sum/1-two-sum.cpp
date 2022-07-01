class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> values;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(values.find(target-nums[i])!=values.end())
                return {i,values.find(target-nums[i])->second};
            else
                values.insert(make_pair(nums[i],i));
        }
        return {};
    }
};