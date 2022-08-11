class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> count;
        for(int i=0;i<nums.size();i++)
            count[nums[i]]++;
        
        for(auto i: count)
            if(i.second>(nums.size()/2))
                return i.first;
        return 0;
    }
};