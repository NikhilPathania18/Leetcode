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
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(s,p,m-1,n-1,dp);
    }
};