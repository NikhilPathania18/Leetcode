class Solution {
public:
    int path(vector<vector<int>>& grid,int row,int col,int m,int n,vector<vector<int>>& dp)
    {
        if(row==m-1)
            return dp[row][col]=grid[row][col];
        if(dp[row][col]!=-1)
            return dp[row][col];
        int left,bottom,right;
        left=bottom=right=INT_MAX;
        if(col>0)
            left=path(grid,row+1,col-1,m,n,dp);
        if(col<n-1)
            right=path(grid,row+1,col+1,m,n,dp);
        bottom=path(grid,row+1,col,m,n,dp);
        return dp[row][col]=min(left,min(right,bottom))+grid[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            dp[m-1][i]=matrix[m-1][i];
        }
        for(int row=m-2;row>=0;row--)
        {
            for(int col=0;col<n;col++)
            {
                int left,right,bottom;
                left=right=bottom=INT_MAX;
                if(col>0)
                    left=dp[row+1][col-1];
                if(col<n-1)
                    right=dp[row+1][col+1];
                bottom=dp[row+1][col];
                dp[row][col]=min(left,min(right,bottom))+matrix[row][col];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
            ans=min(ans,dp[0][i]);
        return ans;
        
    }
};