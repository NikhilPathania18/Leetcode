class Solution {
public:
    int solve(vector<vector<int>>& grid, int row,int c1,int c2,int m,int n,vector<vector<vector<int>>> &dp)
    {
        if(c1<0||c1>=n||c2<0||c2>=n)
            return 0;
        if(row==m)
            return 0;
        
        if(dp[row][c1][c2]!=-1)
            return dp[row][c1][c2];
        int value=0;
        if(c1==c2)
            value=grid[row][c1];
        else
            value=grid[row][c1]+grid[row][c2];
        int ans=INT_MIN;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                ans=max(ans,solve(grid,row+1,c1+i,c2+j,m,n,dp)+value);
            }
        }
        return dp[row][c1][c2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        // vector<vector<vector<int>>> dp(5,vector<int>(3,vector<int>(2,4)));
        return solve(grid, 0,0,n-1,m,n,dp);
    }
};