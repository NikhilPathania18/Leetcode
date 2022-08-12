class Solution {
public:
    void makeZeroes(vector<vector<char>>& grid,int row,int col,int m,int n)
    {
        if(row<0||col<0||row==m||col==n||grid[row][col]=='0')   return;
        grid[row][col]='0';
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(abs(i-j)!=0&&abs(j-i)!=2)
                makeZeroes(grid,row+i,col+j,m,n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]=='1')
                {
                    count++;
                    makeZeroes(grid,row,col,m,n);
                }
            }
        }
        return count;
    }
};