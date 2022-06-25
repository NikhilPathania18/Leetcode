class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        if(s=="")
            return true;
        while(j<t.size())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
                if(i==s.size())
                return true;
            }
            else
                j++;
        }
        return false;
    }
};