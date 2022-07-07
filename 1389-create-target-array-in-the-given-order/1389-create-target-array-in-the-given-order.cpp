class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target(nums.size(),-1);
        int size=0;
        for(int i=0;i<nums.size();i++)
        {
            if(index[i]<size)
            {
                int j=size;
                while(j>index[i])
                {
                    target[j]=target[j-1];
                    j--;
                }
                target[index[i]]=nums[i];
                size++;
            }
            else
            {
                target[index[i]]=nums[i];
                size++;
            }
        }
        return target;
    }
};