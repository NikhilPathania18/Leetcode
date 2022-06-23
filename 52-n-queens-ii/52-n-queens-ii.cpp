class Solution {
public:
    int count=0;
    bool isSafeRow(vector<string> &board,int row,int col, int n)
    {
        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        return true;
    }
    bool isSafeUpperDiagonal(vector<string>& board,int row,int col, int n)
    {
        while(row>=0&&col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
            row--;
        }
        return true;
    }
    bool isSafeLowerDiagonal(vector<string>& board,int row,int col,int n)
    {
        while(row<n&&col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
            row++;
        }
        return true;
    }
    bool isSafe(vector<string>& board,int row,int col,int n)
    {
        return isSafeRow(board,row,col,n)&&isSafeUpperDiagonal(board,row,col,n)&&isSafeLowerDiagonal(board,row,col,n);
    }
    
    
    void solve(vector<string>& board,int col,int n)
    {
        if(col==n)
        {
            count++;
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,i,col,n))
            {
                board[i][col]='Q';
                solve(board,col+1,n);
                board[i][col]='.';
            }
        }
        
    }
   
    
    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        solve(board,0,n);
        return count;
    }
};