class Solution {
public:
    
    void comb(vector<int>& candidates,vector<int>& arr,int index,int target,vector<vector<int>> &result)
    {
        if(target==0)
        {
            result.push_back(arr);
            return;
        }
        if(index==candidates.size())
            return;
        if(target<0)
            return;
        for(int i=index;i<candidates.size();i++)
        {
            if(i>index&&candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
                break;
            
            arr.push_back(candidates[i]);
            comb(candidates,arr,i+1,target-candidates[i],result);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
        vector<int> arr;
        comb(candidates,arr,0,target,result);
        return result;
    }
};