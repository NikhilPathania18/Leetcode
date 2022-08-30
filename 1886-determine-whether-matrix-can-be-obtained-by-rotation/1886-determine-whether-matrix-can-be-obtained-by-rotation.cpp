class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        int degree=3;
        if(mat==target) return true;
        while(degree--)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<i;j++)
                {
                    swap(mat[i][j],mat[j][i]);
                }
            }
            for(int i=0;i<n;i++)
            {
            reverse(mat[i].begin(),mat[i].end());
            }
        
            if(mat==target) return true;
            }
        
        return false;
    }
};