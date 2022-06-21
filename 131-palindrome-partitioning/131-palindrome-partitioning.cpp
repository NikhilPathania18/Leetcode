class Solution {
public:
    bool isPalindrome(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    
    void solve(vector<vector<string>> &ans,vector<string>& arr, string s)
    {
        if(s=="")
        {
            ans.push_back(arr);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
            if(isPalindrome(s.substr(0,i+1)))
            {
                arr.push_back(s.substr(0,i+1));
                solve(ans,arr,s.substr(i+1,s.size()-1));
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> arr;
        solve(ans,arr,s);
        return ans;
    }
};