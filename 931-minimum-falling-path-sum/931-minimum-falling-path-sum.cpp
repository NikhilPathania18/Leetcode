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
        int ans=INT_MAX;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            ans=min(ans,path(matrix,0,i,m,n,dp));
        }
        return ans;
    }
};