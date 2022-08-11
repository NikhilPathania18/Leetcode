class Solution {
public:
    int majorityElement(vector<int>& nums) {
//         map<int,int> count;
//         for(int i=0;i<nums.size();i++)
//             count[nums[i]]++;
        
//         for(auto i: count)
//             if(i.second>(nums.size()/2))
//                 return i.first;
//         return 0;
        
        sort(nums.begin(),nums.end());
        int count=1,maxL=0;
        int num=nums[0];
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
                count++;
            else
                count=1;
            if(count>nums.size()/2)
                num=nums[i];
        }
        return num;
    }
};