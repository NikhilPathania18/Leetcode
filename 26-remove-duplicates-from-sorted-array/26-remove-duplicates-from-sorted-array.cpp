class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        int curr=0,next=1;
        while(next<size)
        {
            if(nums[next]==nums[curr])  next++;
            else{
                nums[++curr]=nums[next];
                next++;
            }
        }
        return curr+1;
    }
};