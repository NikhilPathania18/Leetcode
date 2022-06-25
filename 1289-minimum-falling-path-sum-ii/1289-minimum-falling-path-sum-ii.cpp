class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        vector<vector<int>>dp(m,vector<int>(m));
        for(int i=0;i<m;i++)
            dp[m-1][i]=grid[m-1][i];
        for(int row=m-2;row>=0;row--)
        {
            for(int col=0;col<m;col++)
            {
                int temp=INT_MAX;
                for(int i=0;i<m;i++)
                {
                    if(i!=col)
                    temp=min(temp,dp[row+1][i]);
                }
                dp[row][col]=grid[row][col]+temp;
            }
        }
        int ans=INT_MAX;
        for(int col=0;col<m;col++)
            ans=min(ans,dp[0][col]);
        return ans;
    }
};