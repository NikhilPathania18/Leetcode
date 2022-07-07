class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int size=mat.size();
        if(size==1) return mat[0][0];
        for(int i=0;i<size;i++)
        {
            sum+=mat[i][i]+mat[size-1-i][i];
        }
        if(size%2)  sum-=mat[size/2][size/2];
        return sum;
    }
};