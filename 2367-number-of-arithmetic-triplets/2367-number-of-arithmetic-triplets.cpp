class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        
        int n=nums.size();
        int count=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                if(nums[j]-nums[i]==diff&&m[diff+nums[j]]!=0)
                    count++;
            }
        }
        return count;
    }
};