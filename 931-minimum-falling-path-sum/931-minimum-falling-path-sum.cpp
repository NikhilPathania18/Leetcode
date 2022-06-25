class Solution {
public:
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