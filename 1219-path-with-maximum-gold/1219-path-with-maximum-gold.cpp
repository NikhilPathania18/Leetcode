class Solution {
public:
    int getGold(vector<vector<int>>& grid,int x,int y,int m,int n,vector<vector<bool>>& visited)
    {
        visited[x][y]=true;
        int up=0,down=0,right=0,left=0;
        if(x>0&&!visited[x-1][y]&&grid[x-1][y]!=0)
            left=getGold(grid,x-1,y,m,n,visited);
        if(x<m-1&&!visited[x+1][y]&&grid[x+1][y]!=0)
            right=getGold(grid,x+1,y,m,n,visited);
        if(y>0&&!visited[x][y-1]&&grid[x][y-1]!=0)
            up=getGold(grid,x,y-1,m,n,visited);
        if(y<n-1&&!visited[x][y+1]&&grid[x][y+1]!=0)
            down=getGold(grid,x,y+1,m,n,visited);
        visited[x][y]=false;
        return (max(up,max(left,max(right,down))))+grid[x][y];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0)
                    ans=max(ans,getGold(grid,i,j,m,n,visited));
            }
        }
        return ans;
    }
};