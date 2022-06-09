class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        while(i<j)
        {
            if(numbers[i]+numbers[j]==target)
            {
                numbers.resize(2);
                numbers[0]=i+1;
                numbers[1]=j+1;
                return numbers;
            }
            if(numbers[i]+numbers[j]>target)
            {
                j--;
            }
            else if(numbers[i]+numbers[j]<target)
            {
                i++;
            }
        }
        return numbers;
        
    }
};





