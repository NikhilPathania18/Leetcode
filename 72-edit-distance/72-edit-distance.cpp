class Solution {
public:
    int minDist(string &s,string &t,int i1,int i2,vector<vector<int>>& dp)
    {
        if(i1<0||i2<0)
            return dp[i1+1][i2+1]=abs(i1-i2);
        if(dp[i1+1][i2+1]!=-1)
            return dp[i1+1][i2+1];
        if(s[i1]==t[i2])
            return dp[i1+1][i2+1]=minDist(s,t,i1-1,i2-1,dp);
        int insert=1+minDist(s,t,i1,i2-1,dp);
        int del=1+minDist(s,t,i1-1,i2,dp);
        int replace=1+minDist(s,t,i1-1,i2-1,dp);
        return dp[i1+1][i2+1]=min(insert,min(del,replace));
    }
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<=n;i++)   dp[0][i]=i;
        for(int j=0;j<=m;j++)   dp[j][0]=j;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                {
                    int insert=1+dp[i][j-1];
                    int del=1+dp[i-1][j];
                    int replace=1+dp[i-1][j-1];
                    dp[i][j]=min(insert,min(del,replace));
                }
            }
        }
        return dp[m][n];
    }
};