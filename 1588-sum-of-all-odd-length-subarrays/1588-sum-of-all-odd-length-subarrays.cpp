class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        int size=arr.size();
        vector<int> prefixSum(size);
        prefixSum[0]=arr[0];
        for(int i=1;i<size;i++)
        {
            prefixSum[i]=prefixSum[i-1]+arr[i];
        }
        
        for(int i=0;i<size;i++)
        {
            int prevSum=0;
            if(i>0)
                prevSum=prefixSum[i-1];
            for(int j=i;j<size;j+=2)
            {
                sum+=prefixSum[j]-prevSum;
            }
        }
        return sum;
        
    }
};