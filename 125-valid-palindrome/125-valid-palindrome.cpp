class Solution {
public:
    bool isP(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    bool isPalindrome(string s) {
        if(s.size()==1)
            return true;
        int i=0;
        while(i<s.size())
        {
            if(isupper(s[i]))
                s[i]=tolower(s[i]);
            else if(!isalpha(s[i])&&!isdigit(s[i]))
            {
                s.erase(s.begin()+i,s.begin()+i+1);
                i--;
            }
            i++;
        }
        return isP(s);
    }
};