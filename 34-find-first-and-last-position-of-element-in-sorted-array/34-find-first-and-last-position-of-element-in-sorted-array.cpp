class Solution {
public:
    int BST(vector<int>&nums,int target,int left,int right)
    {
        if(left>right)
            return -1;
        int mid=(left+right)/2;
        if(nums[mid]==target)
            return mid;
        if(target<nums[mid])
            return BST(nums,target,left,mid-1);
        return BST(nums,target,mid+1,right);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos=BST(nums,target,0,nums.size()-1);
        vector<int> ans(2,-1);
        if(pos==-1)
            return ans;
        int left=pos,right=pos;
        while(left>=0)
        {
            if(nums[left]!=nums[pos])
                break;
            left--;
        }
        while(right<nums.size())
        {
            if(nums[right]!=nums[pos])
                break;
            right++;
        }
        ans[0]=left+1;
        ans[1]=right-1;
        return ans;
    }
};