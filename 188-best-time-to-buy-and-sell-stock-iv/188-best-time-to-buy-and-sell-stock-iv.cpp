class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1)));
        for(int i=0;i<=k;i++)
            dp[n][0][i]=dp[n][1][i]=0;
        for(int index=n-1;index>=0;index--)
        {
            for(int hasBought=0;hasBought<=1;hasBought++)
            {
                for(int remaining=0;remaining<=k;remaining++)
                {
                    if(hasBought)
                        dp[index][hasBought][remaining]=max(prices[index]+dp[index+1][0][remaining],dp[index+1][1][remaining]);
                    else if(remaining==0)
                        dp[index][hasBought][remaining]=0;
                    else
                        dp[index][hasBought][remaining]=max(-1*prices[index]+dp[index+1][1][remaining-1],dp[index+1][0][remaining]);
                }
            }
        }
        return dp[0][0][k];
    }
};