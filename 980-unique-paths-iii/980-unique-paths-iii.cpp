class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<bool>>& hasMoved,int row,int col,int endRow,int endCol,int m,int n)
    {
        if(grid[row][col]==-1)
            return 0;
        if(row==endRow&&col==endCol)
        {
            for(int i=0;i<=m;i++)
            {
                for(int j=0;j<=n;j++)
                {
                    if(grid[i][j]==-1)
                        continue;
                    if(hasMoved[i][j]==false)
                        return 0;
                }
            }
            return 1;
        }
        
        int up,left,down,right;
        up=left=down=right=0;
        if(row>0&&hasMoved[row-1][col]==false)
        {
            hasMoved[row-1][col]=true;
            up=solve(grid,hasMoved,row-1,col,endRow,endCol,m,n);
            hasMoved[row-1][col]=false;
        }
        if(col>0&&hasMoved[row][col-1]==false)
        {
            hasMoved[row][col-1]=true;
            left=solve(grid,hasMoved,row,col-1,endRow,endCol,m,n);
            hasMoved[row][col-1]=false;
        }
        if(col<n&&hasMoved[row][col+1]==false)
        {
            hasMoved[row][col+1]=true;
            right=solve(grid,hasMoved,row,col+1,endRow,endCol,m,n);
            hasMoved[row][col+1]=false;
        }
        if(row<m&&hasMoved[row+1][col]==false)
        {
            hasMoved[row+1][col]=true;
            down=solve(grid,hasMoved,row+1,col,endRow,endCol,m,n);
            hasMoved[row+1][col]=false;
        }
        return up+left+down+right;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> hasMoved(m,vector<bool>(n,false));
        pair<int,int> start,end;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    start=make_pair(i,j);
                else if(grid[i][j]==2)
                    end=make_pair(i,j);
            }
        }
        hasMoved[start.first][start.second]=true;
        return solve(grid,hasMoved,start.first,start.second,end.first,end.second,m-1,n-1);
    }
};