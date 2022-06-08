class Solution {
public:
    void merge(vector<int>& nums1, int i, vector<int>& nums2, int j) {
       
        int k=i+j-1;
        i--;
        j--;
        while(i>=0&&j>=0)
        {
            if(nums2[j]>nums1[i])
            {
                nums1[k--]=nums2[j--];
            }
            else
            {
                nums1[k--]=nums1[i--];
            }
        }
        while(j>=0)
        {
            nums1[k--]=nums2[j--];
        }
        
    }
};