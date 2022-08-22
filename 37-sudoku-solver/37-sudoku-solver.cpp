class Solution {
public:
    bool inRow(vector<vector<char>>& board,int row,int col,char num)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==num)
                return true;
        }
        return false;
    }
    bool inCol(vector<vector<char>>& board,int row,int col,char num)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==num)
                return true;
        }
        return false;
    }
    bool inBox(vector<vector<char>>& board,int row,int col,char num)
    {
        int rowStart=row-row%3;
        int colStart=col-col%3;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[rowStart+i][colStart+j]==num)  return true;
            }
        }
        return false;
    }
    bool checkSudoku(vector<vector<char>>& board,int row,int col)
    {
        if(col==9)
        {
            col=0;
            row++;
        }
        if(row==9)
            return true;
        
        if(board[row][col]!='.')
        return checkSudoku(board,row,col+1);
            for(int i=1;i<=9;i++)
            {
                if(!inRow(board,row,col,i+'0')&&!inCol(board,row,col,i+'0')&&!inBox(board,row,col,i+'0'))
                {
                    board[row][col]=i+'0';
                    if(checkSudoku(board,row,col+1))    return true;
                    board[row][col]='.';
                }
            }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        checkSudoku(board,0,0);
    }
};