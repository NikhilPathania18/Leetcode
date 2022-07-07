class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        int curr=0,next=1;
        while(next<size)
        {
            if(nums[next]==nums[curr])  next++;
            else{
                nums[curr+1]=nums[next];
                next++;
                curr++;
            }
        }
        return curr+1;
    }
};