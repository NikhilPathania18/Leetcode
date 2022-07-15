class Solution {
public:
    int getArea(vector<vector<int>>& grid,int row,int col,int m,int n)
    {
        if(row<0||col<0||row>=m||col>=n||!grid[row][col])
            return 0;
        grid[row][col]=0;
        return 1+getArea(grid,row+1,col,m,n)+getArea(grid,row,col+1,m,n)+getArea(grid,row-1,col,m,n)+getArea(grid,row,col-1,m,n);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxArea=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j])
                    maxArea=max(maxArea,getArea(grid,i,j,m,n));
        return maxArea;
    }
};