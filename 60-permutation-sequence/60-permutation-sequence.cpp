class Solution {
public:
    int fact(int n)
    {
        if(n<=1)
            return 1;
        return n*fact(n-1);
    }
    string solve(string str,vector<char> &nums,int n,int k)
    {
        if(n==0)
            return str;
        int total=fact(n);
        int perSet=total/n;
        
        int whichSet=(k)/perSet;
        int whatNo=(k)%perSet;
        
        str.push_back(nums[whichSet]);
        nums.erase(nums.begin()+whichSet);
        return solve(str,nums,n-1,whatNo);
    }
    string getPermutation(int n, int k) {
        string str="";
        vector<char> nums;
        for(int i=0;i<n;i++)
        {
            nums.push_back('0'+i+1);
        }
        return solve(str,nums,n,k-1);
    }
};