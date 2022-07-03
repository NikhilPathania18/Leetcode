class Solution {
public:
    int getProfit(vector<int>& prices,int n,int index,int hasBought,vector<vector<int>>& dp)
    {
        if(index>=n)
            return 0;
        if(dp[index][hasBought]!=-1)    return dp[index][hasBought];
        int profit=0;
        if(hasBought)
            profit=max(prices[index]+getProfit(prices,n,index+2,0,dp),getProfit(prices,n,index+1,1,dp));
        else
            profit=max(-1*prices[index]+getProfit(prices,n,index+1,1,dp),getProfit(prices,n,index+1,0,dp));
        return dp[index][hasBought]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return getProfit(prices,n,0,0,dp);
    }
};