// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
void solve(vector<vector<int>>& ans,vector<int>& arr,vector<vector<int>>& grid,int row,int col, int n,int m)
{
    if(row==n-1&&col==m-1)
    {
        arr.push_back(grid[row][col]);
        ans.push_back(arr);
        arr.pop_back();
        return;
    }
    arr.push_back(grid[row][col]);
    if(row<n-1)
    {
        solve(ans,arr,grid,row+1,col,n,m);
    }
    if(col<m-1)
    {
        solve(ans,arr,grid,row,col+1,n,m);
    }
    arr.pop_back();
}
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(ans,arr,grid,0,0,n,m);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends