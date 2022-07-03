class Solution {
public:
    int getProfit(vector<int>& prices,int n, int index, int hasBought,int remaining,vector<vector<vector<int>>> &dp)
    {
        if(index==n)
            return 0;
        if(dp[index][hasBought][remaining]!=-1) return dp[index][hasBought][remaining];
        int profit=0;
        if(hasBought)
        {
            profit=max(prices[index]+getProfit(prices,n,index+1,0,remaining,dp),getProfit(prices,n,index+1,1,remaining,dp));
        }
        else if(remaining==0)   profit=0;
        else
            profit=max(-1*prices[index]+getProfit(prices,n,index+1,1,remaining-1,dp),getProfit(prices,n,index+1,0,remaining,dp));
        return dp[index][hasBought][remaining]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return getProfit(prices,n,0,0,2,dp);
    }
};