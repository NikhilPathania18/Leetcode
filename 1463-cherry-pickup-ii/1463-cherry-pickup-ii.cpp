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
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n)));
        for(int c1=0;c1<n;c1++)
        {
            for(int c2=0;c2<n;c2++)
            {
                if(c1==c2)
                    dp[m-1][c1][c2]=grid[m-1][c1];
                else
                    dp[m-1][c1][c2]=grid[m-1][c1]+grid[m-1][c2];
            }
        }
        for(int row=m-2;row>=0;row--)
        {
            for(int c1=0;c1<n;c1++)
            {
                for(int c2=0;c2<n;c2++)
                {
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
                            if(c1+i<0||c2+j<0||c1+i>=n||c2+j>=n)
                                continue;
                            ans=max(ans,dp[row+1][c1+i][c2+j]+value);
                        }
                    }
                    dp[row][c1][c2]=ans;
                }
            }
        }
        return dp[0][0][n-1];
    }
};