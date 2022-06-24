class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        //Consider last element in not there in ans
        int prev1=max(nums[0],nums[1]);
        int prev2=nums[0];
        for(int i=2;i<nums.size()-1;i++)
        {
            int take=nums[i]+prev2;
            int notTake=prev1;
            int curr=max(take,notTake);
            prev2=prev1;
            prev1=curr;
        }
        int ans1=prev1;
        
        //Consider first element is not there in ans
        prev2=nums[1];
        prev1=max(nums[1],nums[2]);
        for(int i=3;i<nums.size();i++)
        {
            int take=nums[i]+prev2;
            int notTake=prev1;
            int curr=max(take,notTake);
            prev2=prev1;
            prev1=curr;
        }
        int ans2=prev1;
        return max(ans1,ans2);
    }
};