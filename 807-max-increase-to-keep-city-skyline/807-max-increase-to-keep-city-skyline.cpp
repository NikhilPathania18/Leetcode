class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int sum=0;
        vector<int> rowmax;
        vector<int> colmax;
        for(int i=0;i<grid.size();i++)
        {
            int big=grid[i][0];
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]>big)
                    big=grid[i][j];
            }
            rowmax.push_back(big);
        }
        for(int j=0;j<grid.size();j++)
        {
            int big2=grid[0][j];
            for(int i=0;i<grid.size();i++)
            {
                if(grid[i][j]>big2)
                    big2=grid[i][j];
            }
            colmax.push_back(big2);
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                sum+=min(rowmax[i],colmax[j])-grid[i][j];
            }
        }
        return sum;
        
        
    }
};