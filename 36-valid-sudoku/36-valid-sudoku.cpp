class Solution {
public:
    bool inRow(int row,int col,vector<vector<char>>& board)
    {
        char num=board[row][col];
        for(int i=0;i<9;i++)
        {
            if(i==col)
                continue;
            if(board[row][i]==num)
                return true;
        }
        return false;
    }
    bool inCol(int row,int col, vector<vector<char>>& board)
    {
        char num=board[row][col];
        for(int i=0;i<9;i++)
        {
            if(i==row)
                continue;
            if(board[i][col]==num)
                return true;
        }
        return false;
    }
    bool inBox(int rowStart,int colStart,vector<vector<char>>& board,char num,int r,int c)
    {
        for(int row=0;row<3;row++)
        {
            for(int col=0;col<3;col++)
            {
                if(row+rowStart==r&&col+colStart==c)
                    continue;
                if(board[row+rowStart][col+colStart]==num)
                    return true;
            }
        }
        return false;
        
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(inRow(i,j,board)||inCol(i,j,board)||inBox(i-i%3,j-j%3,board,board[i][j],i,j))
                        return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
};