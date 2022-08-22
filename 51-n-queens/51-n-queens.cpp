class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board,int n)
    {
        int x=row,y=col;
        while(y>=0)
        {
            if(board[x][y]=='Q')    return false;
            y--;
        }
        
        x=row;
        y=col;
        while(x>=0&&y>=0)
        {
            if(board[x--][y--]=='Q')    return false;
        }
        
        x=row;
        y=col;
        while(x<n&&y>=0)
            if(board[x++][y--]=='Q')    return false;
        
        return true;
    }
    
    void solve(vector<vector<string>>& ans,vector<string>& board,int col,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isSafe(i,col,board,n))
            {
                board[i][col]='Q';
                solve(ans,board,col+1,n);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board;
        for(int i=0;i<n;i++)
            board.push_back(s);
        solve(ans,board,0,n);
        return ans;
    }
};