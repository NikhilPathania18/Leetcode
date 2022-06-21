class Solution {
public:
    string invertNreverse(string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
                s[i]='1';
            else
                s[i]='0';
        }
        int i=0,j=s.size()-1;
        while(i<j)
        {
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
        return s;
    }
    string sN(int n)
    {
        if(n==1)
            return "0";
        string s=sN(n-1);
        return s+"1"+invertNreverse(s);
        
        
        // vector<string> dp(n);
        // dp[0]="0";
        // for(int i=1;i<n;i++)
        // {
        //     dp[i]=dp[i-1]+"1"+invertNreverse(dp[i-1]);
        // }
        // return dp[n-1];
    }
    char findKthBit(int n, int k) {
        string sNth=sN(n);
        return sNth[k-1];
    }
};