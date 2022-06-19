class Solution {
public:
    vector<vector<int>> ans;
    void comb(vector<int>& candidates,vector<int> &arr,int index,int target)
    {
        if(index==candidates.size())
        {
            if(target==0)
            {
            ans.push_back(arr);
            return;
            }
            return;
        }
        
        if(target<0)
            return;
        arr.push_back(candidates[index]);
        comb(candidates,arr,index,target-candidates[index]);
        arr.pop_back();
        comb(candidates,arr,index+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        comb(candidates,arr,0,target);
        return ans;
    }
};