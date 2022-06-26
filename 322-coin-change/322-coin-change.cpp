class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
                dp[0][i]=i/coins[0];
            else
                dp[0][i]=1e9;
        }
        for(int i=0;i<n;i++)
            dp[i][0]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                int take=INT_MAX;
                if(coins[i]<=j)
                    take=dp[i][j-coins[i]]+1;
                int notTake=dp[i-1][j];
                dp[i][j]=min(take,notTake);
            }
        }
        
        if(dp[n-1][amount]>=1e9)
            return -1;
        else
            return dp[n-1][amount];
    }
};