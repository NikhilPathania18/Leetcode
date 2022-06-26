class Solution {
public:
    
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return false;
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
        if(sum%2==1)
            return false;
        int k=sum/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));
        for(int i=0;i<n;i++)
            dp[i][0]=true;
        if(arr[0]<=k)
        dp[0][arr[0]]=true;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                bool take=false;
                if(arr[i]<=j)
                    take=dp[i-1][j-arr[i]];
                if(take)
                {
                    dp[i][j]=true;
                    continue;
                }
                if(dp[i-1][j])
                {
                    dp[i][j]=true;
                    continue;
                }
                dp[i][j]=false;
            }
        }
        return dp[n-1][k];
    }
};