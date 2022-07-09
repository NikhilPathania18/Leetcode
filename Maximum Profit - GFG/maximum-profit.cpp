// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int getProfit(int A[],int n, int index,int k,bool hasBought)
  {
      if(index==n)
      return 0;
      int profit=0;
      if(hasBought)
      {
          profit=max(profit,A[index]+getProfit(A,n,index+1,k,0));
          profit=max(profit,getProfit(A,n,index+1,k,1));
      }
      
      else
      {
          if(k>0)
          profit=max(profit,-1*A[index]+getProfit(A,n,index+1,k-1,1));
          profit=max(profit,getProfit(A,n,index+1,k,0));
      }
      return profit;
  }
    int maxProfit(int k, int n, int A[]) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,0)));
        for(int index=n-1;index>=0;index--)
        {
            for(int remaining=k;remaining>=0;remaining--)
            {
                for(int hasBought=0;hasBought<=1;hasBought++)
                {
                    int profit=0;
                    if(hasBought)
                    {
                        profit=max(profit,A[index]+dp[index+1][remaining][0]);
                        profit=max(profit,dp[index+1][remaining][1]);
                    }
                    else
                    {
                        if(remaining>0)
                        profit=max(profit,-1*A[index]+dp[index+1][remaining-1][1]);
                        profit=max(profit,dp[index+1][remaining][0]);
                    }
                    dp[index][remaining][hasBought]=profit;
                }
            }
        }
        return dp[0][k][0];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends