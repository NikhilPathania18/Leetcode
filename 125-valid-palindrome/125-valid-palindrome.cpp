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
    bool isPalindrome(string s)
    {
        string str;
        int i=0;
        while(i<s.size())
        {
            if(isalpha(s[i]))
                str.push_back(tolower(s[i]));
            else if(isdigit(s[i]))
                str.push_back(s[i]);
            i++;
        }
        return isP(str);
    }
};