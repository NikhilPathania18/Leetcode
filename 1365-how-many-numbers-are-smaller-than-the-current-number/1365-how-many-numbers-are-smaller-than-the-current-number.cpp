class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101,0);
        for(int i=0;i<nums.size();i++)
            freq[nums[i]]++;
        for(int i=1;i<101;i++)
        {
            freq[i]+=freq[i-1];
        }
        vector<int> arr(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                arr[i]=0;
            else
                arr[i]=freq[nums[i]-1];
        }
        return arr;
    }
};