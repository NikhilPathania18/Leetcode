class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ch;
        int length=0,maxlength=0;
        for(int i=0;i<s.size();i++)
        {
            if(ch.find(s[i])==ch.end())
            {
                length++;
                ch.insert(s[i]);
            }
            else
            {
                maxlength=max(length,maxlength);
                length=0;
                i-=ch.size();
                ch.clear();
            }
        }
        return max(maxlength,length);
    }
};