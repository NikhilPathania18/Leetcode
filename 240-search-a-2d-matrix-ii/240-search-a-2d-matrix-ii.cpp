class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Start from top right corner   --If target is less than curr index, move left else move down
        
        
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0,j=n-1;
        while(i<m&&j>=0)
        {
            if(matrix[i][j]==target)    return true;
            if(target<matrix[i][j])
                j--;
            else
                i++;
        }
        return false;
    }
};