
class Solution {
public: string longestPalindrome(string s) {
        int i,j,k=0;
        int maxL=1;
        int currLen;
        string largest;
        largest.push_back(s[0]);
        for(k;k<s.size();k++)
        {
            i=k-1;
            j=k+1;
            while((i>=0&&j<s.size())&&(s[i]==s[j]))
            {
                i--;
                j++;
            }
            currLen=j-i-1;
            if(currLen>maxL)
            {
                maxL=currLen;
                largest=s.substr(i+1,currLen);
            }
            //-----------> Second case
            i=k-1;
            j=k;
            while((i>=0&&j<s.size())&&(s[i]==s[j]))
            {
                i--;
                j++;
            }
            currLen=j-i-1;
            if(currLen>maxL)
            {
                maxL=currLen;
                largest=s.substr(i+1,currLen);
            }
        }
        return largest;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};