class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0||n==1)
            return n;
        vector<int> num(n+1);
        num[0]=0;
        
        num[1]=1;
        int ans=1;
        for(int i=2;i<=n;i++)
        {
            if(i%2==0)
                num[i]=num[i/2];            
            else
                num[i]=num[(i-1)/2]+num[(i+1)/2];
            
            ans=max(ans,num[i]);
        }
        return ans;
    }
};