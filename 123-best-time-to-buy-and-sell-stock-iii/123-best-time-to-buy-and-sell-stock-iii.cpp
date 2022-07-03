class Solution {
public:
    int getProfit(vector<int>& prices,int n, int index, int hasBought,int remaining,vector<vector<vector<int>>> &dp)
    {
        if(index==n)
            return 0;
        if(dp[index][hasBought][remaining]!=-1) return dp[index][hasBought][remaining];
        int profit=0;
        if(hasBought)
        {
            profit=max(prices[index]+getProfit(prices,n,index+1,0,remaining,dp),getProfit(prices,n,index+1,1,remaining,dp));
        }
        else if(remaining==0)   profit=0;
        else
            profit=max(-1*prices[index]+getProfit(prices,n,index+1,1,remaining-1,dp),getProfit(prices,n,index+1,0,remaining,dp));
        return dp[index][hasBought][remaining]=profit;
    }
    
    
    
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3)));
        vector<vector<int>> temp(2,vector<int>(3));
        vector<vector<int>> curr(2,vector<int>(3));
        for(int i=0;i<3;i++)
            temp[0][i]=temp[1][i]=0;
        for(int index=n-1;index>=0;index--)
        {
            for(int hasBought=0;hasBought<=1;hasBought++)
            {
                for(int remaining=0;remaining<3;remaining++)
                {
                    if(hasBought)
                        curr[hasBought][remaining]=max(prices[index]+temp[0][remaining],temp[1][remaining]);
                    
                    else if(remaining==0)   curr[hasBought][remaining]=0;
                    else
                        curr[hasBought][remaining]=max(-1*prices[index]+temp[1][remaining-1],temp[0][remaining]);
                        
                }
            }
            temp=curr;
        }
        return curr[0][2];
    }
};