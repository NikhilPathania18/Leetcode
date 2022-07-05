class Solution {
public:
    bool solve(vector<int>& nums,int index,int n,vector<int>& dp)
    {
        if(index==n-1)
            return true;
        if(dp[index]!=-1)   return dp[index];
        if(nums[index]==0)
            return dp[index]=false;
        for(int i=1;i<=nums[index];i++)
        {
            if(i+index<n&&solve(nums,i+index,n,dp))
                return dp[index]=true;
        }
        return dp[index]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,nums.size(),dp);
    }
};