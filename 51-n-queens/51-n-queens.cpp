class Solution {
public:
    bool isSafe(int row,int col,vector<string> &board,int n)
    {
        int x=row;
        int y=col;
        
        //To check upper left diagonal
        while(x>=0&&y>=0)
        {
            if(board[x][y]=='Q')
                return false;
            x--;
            y--;
        }
        
        //To check back side of row
        x=row;
        y=col;
        
        while(y>=0)
        {
            if(board[x][y]=='Q')
                return false;
            y--;
        }
        
        //To check lower diagonal
        x=row;
        y=col;
        while(y>=0&&x<n)
        {
            if(board[x][y]=='Q')
                return false;
            x++;
            y--;
        }
        
        return true;
    }
    
    void solve(int col,vector<string> &board,int n,vector<vector<string>>& ans)
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
                solve(col+1,board,n,ans);
                board[i][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        solve(0,board,n,ans);
        return ans;
    }
};