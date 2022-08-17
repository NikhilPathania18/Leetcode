class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& arr,int index,int n,int k)
    {
        
        if(arr.size()==k)
        {
            ans.push_back(arr);
            return;
        }
        if(index>n) return;
        //take
        arr.push_back(index);
        solve(ans,arr,index+1,n,k);
        arr.pop_back();
        
        //notTake
        solve(ans,arr,index+1,n,k);
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        vector<vector<int>> ans;
        solve(ans,arr,1,n,k);
        return ans;
    }
};