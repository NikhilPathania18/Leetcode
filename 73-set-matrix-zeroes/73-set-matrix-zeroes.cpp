class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> pos;
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                    pos.push_back({i,j});
                
            }
        }
        for(int i=0;i<pos.size();i++)
        {
            for(int col=0;col<n;col++)
                matrix[pos[i][0]][col]=0;
            for(int row=0;row<m;row++)
                matrix[row][pos[i][1]]=0;
        }
        
    }
};