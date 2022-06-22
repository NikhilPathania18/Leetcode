class Solution {
public:
    string solve(vector<char>& nums, string &arr, int index,int n,int k,vector<bool> &isTaken,vector<string>& ans)
    {
    
        if(arr.size()==n)
        {
              ans.push_back(arr) ;
                if(ans.size()==k)
                    return ans[ans.size()-1];
                return "";
        }
        for(int i=0;i<n;i++)
        {
            if(isTaken[i])
                continue;
            
            arr.push_back(nums[i]);
            isTaken[i]=true;
            string str=solve(nums,arr,index+1,n,k,isTaken,ans);
            if(str!="")
                return str;
            isTaken[i]=false;
            arr.pop_back();
        }
        return "";
    }
    string getPermutation(int n, int k) {
        vector<char> nums;
        for(int i=0;i<n;i++)
            nums.push_back('0'+i+1);
        vector<bool> isTaken(n,false);
        vector<string> ans;
        string arr="";
        return solve(nums,arr,0,n,k,isTaken,ans);
        
    }
};