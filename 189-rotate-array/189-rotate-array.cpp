class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        int size=nums.size();
        
        k=k%size;
        for(int i=size-k;i<size;i++)
            temp.push_back(nums[i]);
        
        for(int i=size-1;i>=k;i--)
            nums[i]=nums[i-k];
        for(int i=0;i<k;i++)
        {
            nums[i]=temp[i];
            // cout<<temp[i]<<" ";
        }
        
    }
};