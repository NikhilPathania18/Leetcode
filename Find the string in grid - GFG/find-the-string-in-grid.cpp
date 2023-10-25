//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isFound(vector<vector<char>> &grid, string word, int index,int row, int col, int x_dir, int y_dir){
        if(index==word.size())  return true;
        if(row<0||col<0||row==grid.size()||col==grid[0].size()) return false;
        if(grid[row][col]!=word[index]) return false;
        
        return isFound(grid,word,index+1,row+x_dir,col+y_dir,x_dir,y_dir);
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> direction = {
	        {-1,-1,-1,0,0,1,1,1},
	        {-1,0,1,-1,1,-1,0,1}
	    };
	    
	    vector<vector<int>> ans;
	    
	    for(int row = 0; row<grid.size(); row++){
	        for(int col = 0; col<grid[0].size(); col++){
	            for(int dir = 0; dir<8; dir++){
	                bool isWordFound = isFound(grid, word, 0, row, col, direction[0][dir], direction[1][dir]);
	                if(isWordFound) {
	                    ans.push_back({row,col});
	                    break;
	                }
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends