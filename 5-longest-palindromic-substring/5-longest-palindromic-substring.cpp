
class Solution {
public:
    string func(string s)
    {
        
        if(s=="")
            return "";
        if(s.size()==1)
            return s;
        int i,j,k=0,len=1;
        string str;
        while(k<s.size())
        {
            i=k-1;
            j=k+1;
            while(i>=0&&j<s.size())
            {
                if(s[i]!=s[j])
                    break;
                i--;
                j++;
            }
            if(j-i+1>len)
            {
                len=j-i+1;
                str="";
                str=s.substr(i+1,j-i+1);
            }
            i=k-1;
            j=k;
            while(i>=0&&j<s.size())
            {
                if(s[i]!=s[j])
                    break;
                i--;
                j++;
            }
            if(j-i+1>len)
            {
                str="";
                str=s.substr(i+1,j-i+1);
                len=j-i+1;
            }
            k++;
        }
        return str;
    }
    
    
    
    string longestPalindrome(string s) {
        int i,j,k=0;
        int maxL=1;
        string largest;
        largest.push_back(s[0]);
        int size=s.size();
        int currLen;
        for(int k=0;k<size;k++)
        {
            i=k-1;
            j=k+1;
            while((i>=0&&j<size)&&(s[i]==s[j]))
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
        for(int k=0;k<size;k++)
        {
            i=k-1;
            j=k;
            while((i>=0&&j<size)&&(s[i]==s[j]))
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