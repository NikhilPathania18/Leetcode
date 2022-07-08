class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int size=nums.size();
        for (int n=0;n<size;n++)
        if (i < 2 || nums[n] > nums[i-2])
            nums[i++] = nums[n];
        return i;
        
    }
};