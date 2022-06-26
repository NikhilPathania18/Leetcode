class Solution {
public:
    int solve(vector<int>& arr, int n,int amount)
    {
        if(amount==0)
            return 1;
        if(n==0)
        {
            if(amount%arr[0]==0)
                return 1;
            else return 0;
        }
        int take=0;
        if(arr[n]<=amount)
            take=solve(arr,n,amount-arr[n]);
        int notTake=solve(arr,n-1,amount);
        return take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        if(amount==0)
            return 1;
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<n;i++)
            dp[i][0]=1;
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
                dp[0][i]=1;
            else
                dp[0][i]=0;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                int take=0;
                if(coins[i]<=j)
                    take=dp[i][j-coins[i]];
                int notTake=dp[i-1][j];
                dp[i][j]=take+notTake;
            }
        }
        return dp[n-1][amount];
    }
};