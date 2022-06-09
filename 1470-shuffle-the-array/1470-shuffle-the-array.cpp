class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> arr(nums.size());
        int a=0,b=n;
        for(int i=0;i<nums.size();i+=2)
        {
            arr[i]=nums[a++];
            arr[i+1]=nums[b++];
        }
        return arr;
    }
};