class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int row=1;row<m;row++)
            dp[row][0]=1;
        for(int col=1;col<n;col++)
            dp[0][col]=1;
        
        for(int row=1;row<m;row++)
        {
            for(int col=1;col<n;col++)
            {
                int left=dp[row][col-1];
                int up=dp[row-1][col];
                dp[row][col]=left+up;
            }
        }
        return dp[m-1][n-1];
    }
};