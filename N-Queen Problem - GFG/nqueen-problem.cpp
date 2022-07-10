// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool canPlace(vector<vector<int>>& board,int row,int col,int n)
    {
        int x,y;
        
        //Upper Diagonal
        x=row;
        y=col;
        while(x>=0&&y>=0)
        {
            if(board[x][y]==1)
            return false;
            x--;
            y--;
        }
        
        //Lower Diagonal
        x=row;
        y=col;
        while(x<n&&y>=0)
        {
            if(board[x++][y--]==1)  return false;
        }
        
        //Row
        x=row;
        y=col;
        while(y>=0)
        {
            if(board[x][y--]==1)  return false;
        }
        
        return true;
    }
    void solve(vector<vector<int>> &ans,vector<int>& arr,int col,int n,vector<vector<int>>& board)
    {
        if(col==n)
        {
            ans.push_back(arr);
            return;
        }
        
        
        for(int row=0;row<n;row++)
        {
            if(canPlace(board,row,col,n))
            {
                arr.push_back(row+1);
                board[row][col]=1;
                solve(ans,arr,col+1,n,board);
                board[row][col]=0;
                arr.pop_back();
            }
        }
        
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<int>> ans;
        vector<int> arr;
        solve(ans,arr,0,n,board);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends