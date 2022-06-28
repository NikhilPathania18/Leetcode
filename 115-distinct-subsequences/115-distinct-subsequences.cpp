class Solution {
public:
    int distinct(string &s, string& t,int i1,int i2)
    {
        if(i2<0)
            return 1;
        if(i1<0)
            return 0;
        
        int case1=0;
        if(s[i1]==t[i2])
            case1=distinct(s,t,i1-1,i2-1);
        int case2=distinct(s,t,i1-1,i2);
        return case1+case2;
    }
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<double>> dp(m+1,vector<double>(n+1,0));
        for(int i=0;i<=m;i++)
            dp[i][0]=1;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[m][n];
    }
};