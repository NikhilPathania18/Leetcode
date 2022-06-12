class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> arr(image.size(),vector<int> (image.size()));
        for(int i=0;i<image.size();i++)
        {
            for(int j=image[i].size()-1;j>=0;j--)
            {
                if(image[i][j]==0)
                arr[i][image.size()-j-1]=1;
                else 
                    arr[i][image.size()-j-1]=0;
            }
        }
        return arr;
    }
    
};