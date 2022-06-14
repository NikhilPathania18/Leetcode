class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> arr;
        for(int i=0;i<=n;i++)
        {
            vector<int> inner(i+1,1);
            for(int j=1;j<i;j++)
            {
                inner[j]=arr[i-1][j-1]+arr[i-1][j];
            }
            arr.push_back(inner);
        }
        return arr[arr.size()-1];
    }
};