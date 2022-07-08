class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row;
        int m=matrix.size();
        int n=matrix[0].size();
        
        //check for row in which target can be present
        int start=0,end=m-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(matrix[mid][n-1]==target)    return true;
            if(target<matrix[mid][n-1])
                end=mid-1;
            else
                start=mid+1;
        }
        row=end+1;      //Row in which target can be present
        
        if(row>=m)  return false;
        //check for column in which target can be present
        start=0,end=n-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(matrix[row][mid]==target)    return true;
            if(target<matrix[row][mid])
                end=mid-1;
            else
                start=mid+1;
        }
        return false;
    }
};