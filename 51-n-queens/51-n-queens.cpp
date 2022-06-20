class Solution {
public:
//     bool isSafe(int row,int col,vector<string> &board,int n,vector<bool> &ld,vector<bool> &rowD, vector<bool> &rd)
//     {
//         int x=row;
//         int y=col;
        
//         //To check upper left diagonal
//         while(x>=0&&y>=0)
//         {
//             if(board[x][y]=='Q')
//                 return false;
//             x--;
//             y--;
//         }
        
//         //To check back side of row
//         x=row;
//         y=col;
        
//         while(y>=0)
//         {
//             if(board[x][y]=='Q')
//                 return false;
//             y--;
//         }
        
//         //To check lower diagonal
//         x=row;
//         y=col;
//         while(y>=0&&x<n)
//         {
//             if(board[x][y]=='Q')
//                 return false;
//             x++;
//             y--;
//         }
        
//         return true;
//     }
    
    
    bool isSafe(int row,int col,vector<string> &board,int n,vector<bool> &ld,vector<bool> &rowD, vector<bool> &rd)
    {
        if(rd[row+col])
            return false;
        if(rowD[row])
            return false;
        
        //right diagonal formula= (n-1)+(col-row)
        if(ld[(n-1)+(col-row)])
            return false;
        
        return true;
    }
        
    void solve(int col,vector<string> &board,int n,vector<vector<string>>& ans,vector<bool>& leftDiagonal,vector<bool>& rowLine,vector<bool>& rightDiagonal)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isSafe(i,col,board,n,leftDiagonal,rowLine,rightDiagonal))
            {
                board[i][col]='Q';
                rightDiagonal[i+col]=true;
                rowLine[i]=true;
                leftDiagonal[(n-1)+(col-i)]=true;
                solve(col+1,board,n,ans,leftDiagonal,rowLine,rightDiagonal);
                rightDiagonal[i+col]=false;
                rowLine[i]=false;
                leftDiagonal[(n-1)+(col-i)]=false;
                board[i][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        vector<bool> leftDiagonal(2*n-1,false);
        vector<bool> row(n,false);
        vector<bool> rightDiagonal(2*n-1,false);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        solve(0,board,n,ans,leftDiagonal,row,rightDiagonal);
        return ans;
    }
};