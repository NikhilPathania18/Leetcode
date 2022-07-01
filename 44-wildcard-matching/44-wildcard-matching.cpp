class Solution {
public:
    bool solve(string &s,string& p,int i1,int i2,vector<vector<int>>& dp)
    {
        if(i1<0&&i2<0)
            return true;
        if(i2<0&&i1>=0) return false;
        if(i1<0&&i2>=0)
        {
            for(int i=0;i<=i2;i++)
                if(p[i]!='*')
                    return false;
            return true;
        }
        if(dp[i1][i2]!=-1)
            return dp[i1][i2];
        if(s[i1]==p[i2]||p[i2]=='?')
            return dp[i1][i2]=solve(s,p,i1-1,i2-1,dp);
        if(p[i2]=='*')
            return dp[i1][i2]=solve(s,p,i1-1,i2,dp)||solve(s,p,i1,i2-1,dp);
        return dp[i1][i2]=false;
    }
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,true));
        for(int i=1;i<=m;i++)
            dp[i][0]=false;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
                if(p[j-1]!='*')
                    dp[0][i]=false;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                else
                    dp[i][j]=false;
            }
        }
        return dp[m][n];
    }
};