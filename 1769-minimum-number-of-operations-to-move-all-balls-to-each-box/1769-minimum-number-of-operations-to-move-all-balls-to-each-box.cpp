class Solution {
public:
    vector<int> minOperations(string boxes) {
        int size=boxes.size();
        vector<int> index;
        for(int i=0;i<size;i++)
            if(boxes[i]=='1')   index.push_back(i);
        
        
        vector<int> ans(size,0);
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<index.size();j++)
            {
                if(i==index[j]) continue;
                ans[i]+=abs(index[j]-i);
            }
        }
        return ans;
    }
};