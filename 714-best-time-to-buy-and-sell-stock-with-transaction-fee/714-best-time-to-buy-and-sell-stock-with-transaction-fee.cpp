class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> temp(2);
        vector<int> curr(2);
        temp[0]=temp[1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                if(j)
                    curr[j]=max(prices[i]-fee+temp[0],temp[1]);
                else
                    curr[j]=max(-1*prices[i]+temp[1],temp[0]);
            }
            temp=curr;
        }
        return curr[0];
    }
};