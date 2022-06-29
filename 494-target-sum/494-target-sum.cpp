class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(target+sum<0||(target+sum)%2==1)
            return 0;
        int s1=(target+sum)/2;
        
        vector<vector<int>> dp(n,vector<int>(s1+1,0));
        
        for(int i=0;i<=s1;i++)
        {
            if(nums[0]==0&&i==0)
                dp[0][i]=2;
            else if(nums[0]!=0&&i==0)
                dp[0][i]=1;
        }
        if(nums[0]!=0&&nums[0]<=s1)
            dp[0][nums[0]]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=s1;j++)
            {
                int take=0;
                if(nums[i]<=j)
                    take=dp[i-1][j-nums[i]];
                int notTake=dp[i-1][j];
                dp[i][j]=take+notTake;
            }
        }
        
        return dp[n-1][s1];
    }
};