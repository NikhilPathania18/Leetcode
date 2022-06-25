class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=grid[0][0];
        for(int row=1;row<m;row++)
            dp[row][0]=dp[row-1][0]+grid[row][0];
        for(int col=1;col<n;col++)
            dp[0][col]=dp[0][col-1]+grid[0][col];
        for(int row=1;row<m;row++)
        {
            for(int col=1;col<n;col++)
            {
                int left=dp[row][col-1];
                int up=dp[row-1][col];
                dp[row][col]=min(left,up)+grid[row][col];
            }
        }
        return dp[m-1][n-1];
    }
};