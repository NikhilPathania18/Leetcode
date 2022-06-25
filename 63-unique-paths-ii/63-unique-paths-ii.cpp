class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(grid[0][0]==1)
            return 0;
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(row==0&&col==0)
                    dp[0][0]=1;
                else if(grid[row][col]==1)
                    dp[row][col]=0;
                else
                {
                    int up=0,left=0;
                    if(row>0)
                        up=dp[row-1][col];
                    if(col>0)
                        left=dp[row][col-1];
                    dp[row][col]=left+up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};