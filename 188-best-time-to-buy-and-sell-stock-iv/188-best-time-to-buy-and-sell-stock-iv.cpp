class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1)));
        vector<vector<int>> temp(2,vector<int>(k+1));
        vector<vector<int>> curr(2,vector<int>(k+1));
        for(int i=0;i<=k;i++)
            temp[0][i]=temp[1][i]=0;
        for(int index=n-1;index>=0;index--)
        {
            for(int hasBought=0;hasBought<=1;hasBought++)
            {
                for(int remaining=0;remaining<=k;remaining++)
                {
                    if(hasBought)
                        curr[hasBought][remaining]=max(prices[index]+temp[0][remaining],temp[1][remaining]);
                    else if(remaining==0)
                        curr[hasBought][remaining]=0;
                    else
                        curr[hasBought][remaining]=max(-1*prices[index]+temp[1][remaining-1],temp[0][remaining]);
                }
            }
            temp=curr;
        }
        return temp[0][k];
    }
};