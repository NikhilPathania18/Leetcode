class Solution {
public:
    string reverseWords(string s) {
        int x=0,y=0;
        for(int i=0;i<s.size();i++,y++)
        {
            
            if(s[i]==' '||y==s.length()-1)
            {
                if(s[i]==' ')
                y--;
                while(x<y)
                {
                    char temp=s[x];
                    s[x]=s[y];
                    s[y]=temp;
                    x++;
                    y--;
                }
                x=i+1;
                y=i;
            }
                
        }
        return s;
    }
};