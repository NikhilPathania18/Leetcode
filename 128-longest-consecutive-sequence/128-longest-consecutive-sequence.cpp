class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size=nums.size();
        if(size==0) return 0;
        sort(nums.begin(),nums.end());
        int curr=1,maxL=1;
        for(int i=0;i<size-1;i++)
        {
            if(nums[i]==nums[i+1])  continue;
            if(nums[i+1]!=nums[i]+1)
            {
                maxL=max(curr,maxL);
                curr=1;
            }
            else
                curr++;
        }
        return max(curr,maxL);
    }
};