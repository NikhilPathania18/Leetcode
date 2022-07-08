class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
        
        int size=nums.size();
        int curr=0,next=0;
        while(next<size)
        {
            if(nums[curr]==nums[next]&&curr>0&&nums[curr-1]==nums[next])  next++;
            
            else
            {
                curr++;
                nums[curr]=nums[next];
                next++;
            }
        }
        return curr+1;
    }
};