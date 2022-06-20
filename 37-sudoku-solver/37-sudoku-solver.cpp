class Solution {
public:
    bool checkRow(char num, vector<vector<char>> & board, int row, int col)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==num)
                return false;
        }
        return true;
    }
    bool checkCol(char num, vector<vector<char>> &board, int row, int col)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==num)
                return false;
        }
        return true;
    }
    bool checkBox(char num, vector<vector<char>> &board, int row, int col)
    {
        int rowStart,colStart;
        rowStart=row-row%3;
        colStart=col-col%3;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i+rowStart][j+colStart]==num)
                    return false;
            }
        }
        return true;
    }
    
    
    bool canPlace(char num, vector<vector<char>> &board, int row, int col)
    {
        if(checkRow(num,board,row,col)&&checkCol(num,board,row,col)&&checkBox(num,board,row,col))
            return true;
        return false;
    }
    
    bool solve(vector<vector<char>>& board,int row,int col)
    {
        if(col==9)
        {
            col=0;
            row++;
        }
        if(row==9)
            return true;
        
        if(board[row][col]!='.')
            return solve(board,row,col+1);
        
        
        for(int i=1;i<=9;i++)
        {
            if(canPlace('0'+i,board,row,col))
            {
                board[row][col]='0'+i;
                if(solve(board,row,col+1))
                    return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};