class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int x=-1,y=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0&&x==-1)
                x=i;
            else if(nums[i]<0&&y==-1)
                y=i;
            if(x!=-1&&y!=-1)
                break;
        }
        while(ans.size()!=nums.size())
        {
            ans.push_back(nums[x++]);
            while(x<nums.size()&&nums[x]<0)
                x++;
            ans.push_back(nums[y++]);
            while(y<nums.size()&&nums[y]>0)
                y++;
        }
        return ans;
            
    }
};