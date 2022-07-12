class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int size=nums.size();
        bool increasing=true,decreasing=true;
        if(size<=2) return true;
        
        //increasing
        for(int i=0;i<size-1;i++)
        {
            if(nums[i]>nums[i+1])    increasing=false;
            if(nums[i]<nums[i+1])  decreasing=false;
            if(!increasing&&!decreasing)
                return false;
        }
        return true;
    }
};