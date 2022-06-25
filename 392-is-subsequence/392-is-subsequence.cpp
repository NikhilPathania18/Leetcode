class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        int m=s.size();
        int n=t.size();
        if(s=="")
            return true;
        while(j<n)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
                if(i==m)
                return true;
            }
            else
                j++;
        }
        return false;
    }
};