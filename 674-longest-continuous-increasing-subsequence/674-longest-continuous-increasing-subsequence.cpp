class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count=1,maxl=1;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<nums[i+1])
                count++;
            else
            {
                maxl=max(count,maxl);
                count=1;
            }
            
        }
        return max(count,maxl);
    }
};