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
        vector<int> dp(n+1,-1);
        return min(solve(cost,0,cost.size(),dp),solve(cost,1,cost.size(),dp));
    }
};