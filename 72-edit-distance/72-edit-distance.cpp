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
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        return minDist(word1,word2,m-1,n-1,dp);
    }
};