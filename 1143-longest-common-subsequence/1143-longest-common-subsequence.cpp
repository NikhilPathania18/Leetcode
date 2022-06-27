class Solution {
public:
    int solve(string s, string t, int i1,int i2)
    {
        if(i1<0||i2<0)
            return 0;
        if(s[i1]==t[i2])
            return 1+solve(s,t,i1-1,i2-1);
        return max(solve(s,t,i1-1,i2),solve(s,t,i1,i2-1));
    }
    int longestCommonSubsequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            if(s[0]==t[i])  dp[0][i]=1;
            else if(i>0)
                dp[0][i]=dp[0][i-1];
        }
        for(int i=0;i<m;i++)
        {
            if(t[0]==s[i])  dp[i][0]=1;
            else if(i>0)
                dp[i][0]=dp[i-1][0];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(s[i]==t[j])  dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};