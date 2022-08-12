class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<bool>>& visited,int row,int col,int m,int n,int color,int iniColor)
    {
        if(row<0||col<0||row==m||col==n||visited[row][col]||image[row][col]!=iniColor)
            return;
        visited[row][col]=true;
        image[row][col]=color;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(abs(i-j)!=0&&abs(i-j)!=2)
                    dfs(image,visited,row+i,col+j,m,n,color,iniColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int iniColor=image[sr][sc];
        dfs(image,visited,sr,sc,m,n,color,iniColor);
        return image;
    }
};