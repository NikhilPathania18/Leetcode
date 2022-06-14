class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int op=0;           // For using OR (^) operator
        for(int i=0;i<nums.size();i++)
            op=nums[i]^op;
        return op;
    }
};