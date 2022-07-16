class Solution {
public:
    long int mod=1e9+7;
    int solve(int m,int n,int maxMove,int row,int col,vector<vector<vector<double>>>& dp)
    {
        if(row<0||col<0||row>=m||col>=n)    return 1;
        if(dp[maxMove][row][col]!=-1)   return dp[maxMove][row][col];
        if(maxMove<=0) return dp[maxMove][row][col]=0;
        int a,b,c,d;
        a=solve(m,n,maxMove-1,row-1,col,dp);
        b=solve(m,n,maxMove-1,row,col-1,dp);
        c=solve(m,n,maxMove-1,row+1,col,dp);
        d=solve(m,n,maxMove-1,row,col+1,dp);
        return dp[maxMove][row][col]=(a%mod+b%mod+c%mod+d%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int row,int col) {
        vector<vector<vector<double>>> dp(maxMove+1,vector<vector<double>>(m,vector<double>(n,-1)));
        return solve(m,n,maxMove,row,col,dp);
    }
};