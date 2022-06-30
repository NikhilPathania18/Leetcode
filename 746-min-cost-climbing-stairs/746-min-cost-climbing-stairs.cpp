class Solution {
public:
    int solve(vector<int>& cost, int index,int n,vector<int> &dp)
    {
        if(index==n)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int one=solve(cost,index+1,n,dp)+cost[index];
        int two=INT_MAX;
        if(index<n-1)
            two=solve(cost,index+2,n,dp)+cost[index];
        return dp[index]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        dp[0]=cost[n-1];
        dp[1]=cost[n-2];
        for(int i=2;i<n;i++)
        {
            dp[i]=cost[n-i-1]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
        // return min(solve(cost,0,cost.size(),dp),solve(cost,1,cost.size(),dp));
    }
};