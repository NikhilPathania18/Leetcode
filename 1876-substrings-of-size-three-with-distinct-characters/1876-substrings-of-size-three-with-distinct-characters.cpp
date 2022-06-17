class Solution {
public:
    int countGoodSubstrings(string s) {
        int k=0;
        if(s.size()<3)
            return 0;
        int count=0;
        while(k<s.size()-2)
        {
            unordered_set<char> str;
            bool flag=true;
            for(int i=0;i<3;i++)
            {
                if(str.find(s[k+i])!=str.end())
                {
                    flag=false;
                    break;
                }
                else
                    str.insert(s[k+i]);
            }
            if(flag==true)
                count++;
            k++;
        }
        return count;
    }
};