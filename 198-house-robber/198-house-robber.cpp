class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            int pick=nums[i]+prev2;
            int notPick=prev1;
            int curr=max(pick,notPick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};