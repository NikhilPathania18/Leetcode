class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int i=0,curr=0;
        if(nums.size()==1)
            return nums[0];
        while(i<nums.size())
        {
            if(i%4==0)
            {
                nums[curr]=min(nums[i],nums[i+1]);
                i+=2;
                curr++;
            }
            else
            {
                nums[curr]=max(nums[i],nums[i+1]);
                i+=2;
                curr++;
            }
            if(i==nums.size())
            {
                nums.resize(i/2);
                i=0;
                curr=0;
            }
        }
        return nums[0];
    }
};