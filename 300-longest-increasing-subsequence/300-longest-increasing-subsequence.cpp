class Solution {
public:
    int getIndex(vector<int>& arr,int num)
    {
        int start=0,end=arr.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(arr[mid]==num)   return mid;
            if(num<arr[mid])    end=mid-1;
            else    start=mid+1;
        }
        return end+1;
    }
    int binaryApproach(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> arr;
        int size=0;
        for(int i=0;i<n;i++)
        {
            if(size==0||nums[i]>arr[size-1])   {
                arr.push_back(nums[i]);
                size++;
            }
            else
            {
                int index=getIndex(arr,nums[i]);
                arr[index]=nums[i];
            }
        }
        return size;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return binaryApproach(nums);
        
        
        vector<int> dp(n,1);
        int maxl=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i]&&1+dp[j]>dp[i])
                    dp[i]=1+dp[j];
            }
            maxl=max(maxl,dp[i]);
        }
        return maxl;
    }
};