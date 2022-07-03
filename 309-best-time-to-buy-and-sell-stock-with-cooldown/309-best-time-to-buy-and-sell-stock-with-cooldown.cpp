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
        vector<vector<int>> dp(n+2,vector<int>(2));
        for(int i=n+1;i>=n;i--)
            dp[i][0]=dp[i][1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                if(j)
                    dp[i][j]=max(prices[i]+dp[i+2][0],dp[i+1][1]);
                else
                    dp[i][j]=max(-1*prices[i]+dp[i+1][1],dp[i+1][0]);
            }
        }
        return dp[0][0];
    }
};