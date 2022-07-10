class Solution {
public:
    bool isPalindrome(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int longestPalindrome(string s) {
        int n=s.size();
        bool isOdd=false;
        unordered_map<char,int> ch;
        for(int i=0;i<n;i++)
        {
            ch[s[i]]++;
        }
        int count=0;
        for(auto i: ch)
        {
            if(i.second%2==0)
                count+=i.second;
            else
            {
                count+=i.second-1;
                isOdd=true;
            }
        }
        if(isOdd)
            count++;
        return count;
    }
};