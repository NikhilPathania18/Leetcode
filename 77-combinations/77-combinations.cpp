class Solution {
public:
    void combinations(vector<vector<int>>& ans,vector<int>& arr, int index,int n, int k)
    {
        if(arr.size()==k)
        {
            ans.push_back(arr);
            return;
        }
        if(index>n) return;
        
        //take
        arr.push_back(index);
        combinations(ans,arr,index+1,n,k);
        arr.pop_back();
        
        //notTake
        combinations(ans,arr,index+1,n,k);
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> arr;
        combinations(ans,arr,1,n,k);
        return ans;
    }
};