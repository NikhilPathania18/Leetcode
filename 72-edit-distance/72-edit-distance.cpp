class Solution {
public:
    int solve(string &word1,string& word2,int index1,int index2,vector<vector<int>>& dp)
    {
        if(index1<0&&index2<0)  return 0;
        
        if(index2<0)   return index1+1;
        if(index1<0)   return index2+1;
        if(dp[index1][index2]!=-1)  return dp[index1][index2];
        int insert=0,del=0,replace=0;
        if(word1[index1]==word2[index2])
            return dp[index1][index2]=solve(word1,word2,index1-1,index2-1,dp);
        
        insert=1+solve(word1,word2,index1,index2-1,dp);
        del=1+solve(word1,word2,index1-1,index2,dp);
        replace=1+solve(word1,word2,index1-1,index2-1,dp);
        return dp[index1][index2]=min(insert,min(del,replace));
    }
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(word1,word2,m-1,n-1,dp);
    }
};