class Solution {
public:
    int minJumps(vector<int>& nums,int index,int n,vector<int>& dp)
    {
        if(index>=n)
            return 0;
        if(dp[index]!=-1)   return dp[index];
        int minSteps=1e9;
        int steps=0;
        for(int i=1;i<=nums[index];i++)
        {
            steps=minJumps(nums,index+i,n,dp)+1;
            minSteps=min(minSteps,steps);
        }
        return dp[index]=minSteps;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[n-1]=0;
        for(int index=n-2;index>=0;index--)
        {
            int minSteps=1e9;
            int steps=0;
            for(int i=1;i<=nums[index];i++)
            {
                if(index+i<n)
                {
                    steps=dp[index+i]+1;
                    minSteps=min(minSteps,steps);
                }
                
            }
            dp[index]=minSteps;
        }
        return dp[0];
    }
};