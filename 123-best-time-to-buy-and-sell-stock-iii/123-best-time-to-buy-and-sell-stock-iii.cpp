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
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3)));
        for(int i=0;i<3;i++)
            dp[n][0][i]=dp[n][1][i]=0;
        for(int index=n-1;index>=0;index--)
        {
            for(int hasBought=0;hasBought<=1;hasBought++)
            {
                for(int remaining=0;remaining<3;remaining++)
                {
                    if(hasBought)
                        dp[index][hasBought][remaining]=max(prices[index]+dp[index+1][0][remaining],dp[index+1][1][remaining]);
                    
                    else if(remaining==0)   dp[index][hasBought][remaining]=0;
                    else
                        dp[index][hasBought][remaining]=max(-1*prices[index]+dp[index+1][1][remaining-1],dp[index+1][0][remaining]);
                        
                }
            }
        }
        return dp[0][0][2];
    }
};