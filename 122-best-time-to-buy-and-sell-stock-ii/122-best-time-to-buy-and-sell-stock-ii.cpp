class Solution {
public:
    int getProfit(vector<int>& prices,int n,int index,int hasBought)
    {
        if(index==n)    return 0;
        long profit=0;
        if(hasBought)
        {
            profit=max(prices[index]+getProfit(prices,n,index+1,0),getProfit(prices,n,index+1,1));
        }
        else
            profit=max(-1*prices[index]+getProfit(prices,n,index+1,1),getProfit(prices,n,index+1,0));
        return profit;
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                if(j==1)
                    dp[i][j]=max(prices[i]+dp[i+1][0],dp[i+1][1]);
                else
                    dp[i][j]=max(-1*prices[i]+dp[i+1][1],dp[i+1][0]);
            }
        }
        return max(dp[0][0],0);
    }
};