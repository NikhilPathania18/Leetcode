class Solution {
public:
//     bool doesMatch(string &s, string& p,int i1,int i2)
//     {
//         if(i1<0&&i2<0)  return true;
//         if(i2<0&&i1>=0) return false;
//         if(i1<0&&i2>=0)
//         {
//             if(i2==0)   return false;
//             for(int i=0;i<i2;i++)
//                 if(p[i]!='*'&&p[i+1]!='*')
//                     return false;
//             return true;
//         }
        
//         if(s[i1]==p[i2]||p[i2]=='.')    return doesMatch(s,p,i1-1,i2-1);
//         if(p[i2]=='*')
//         {
//             bool with0=doesMatch(s,p,i1,i2-1);
//             bool withMore=false;
//             if((p[i2-1]=='.'||p[i2-1]==s[i1]))
//             {
//                 withMore=doesMatch(s,p,i1-1,i2);
//             }
//             return with0||withMore;
//         }
            
//             // return doesMatch(s,p,i1-1,i2)||doesMatch(s,p,i1,i2-1);
        
//     }
//         return false;
//     }
    bool check(string& s,string &p,int index1,int index2)
    {
        if(index1<0&&index2<0)  return true;
        if(index2<0&&index1>=0) return false;
        if(index1<0&&index2>=0)
        {
            if(index2%2==0)    return false;
            for(int i=0;i<=index2;i++)
            {
                if(i+1<=index2&&p[i+1]!='*')
                    return false;
                i++;
            }
            return true;
        }
        
        if(p[index2]=='.'||p[index2]==s[index1])
            return check(s,p,index1-1,index2-1);
        if(p[index2]=='*')
        {
            bool with0=false,withMore=false;
            with0=check(s,p,index1,index2-2);
            if(s[index1]==p[index2-1]||p[index2-1]=='.')
                withMore=check(s,p,index1-1,index2);
            return with0||withMore;
        }
        return false;
    }
    bool isMatch(string s, string p) {
        
        int m=s.size(),n=p.size();
        return check(s,p,m-1,n-1);
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,true));
        for(int i=1;i<=m;i++)
            dp[i][0]=false;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
                if(p[j-1]!='*')
                    dp[0][i]=false;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='.')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                {
                    bool with0=dp[i][j-1];
                    bool withMore=false;
                    if((p[j-2]=='.'||p[j-2]==s[i-1]))
                    withMore=dp[i-1][j];
                    dp[i][j]= with0||withMore;
                }
                else
                    dp[i][j]=false;
            }
        }
        return dp[m][n];
    }
    // "aab"
    // "c*a*b"
    //should be true
};