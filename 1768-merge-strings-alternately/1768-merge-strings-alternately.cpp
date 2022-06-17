class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i,j;
        i=j=0;
        string s;
        while(i<word1.size()&&j<word2.size())
        {
            s.push_back(word1[i++]);
            s.push_back(word2[j++]);
        }
        if(i==word1.size()&&j!=word2.size())
            s+=word2.substr(j,word2.size()-j);
        else if(i!=word1.size()&&j==word2.size())
            s+=word1.substr(i,word1.size()-i);
        return s;
    }
};