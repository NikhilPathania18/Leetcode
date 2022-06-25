class Solution {
public:
     
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp;
        for(int i=0;i<m;i++)
        {
            vector<int> temp(i+1);
            dp.push_back(temp);
        }
        for(int i=0;i<m;i++)
            dp[m-1][i]=triangle[m-1][i];
        
        for(int row=m-2;row>=0;row--)
        {
            for(int col=0;col<dp[row].size();col++)
            {
                dp[row][col]=min(dp[row+1][col],dp[row+1][col+1])+triangle[row][col];
            }
        }
        return dp[0][0];
    }
};