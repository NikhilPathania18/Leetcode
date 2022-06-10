class Solution {
public:
    
    
    int trap(vector<int>& height) {
        int sum=0;
        int back=height[0];
        stack<int> stk;
        for(int i=0;i<height.size();i++)
        {
            if(height[i]-back<0)
            {
                stk.push(height[i]);
            }
            else
            {
                while(!stk.empty())
                {
                    sum+=back-stk.top();
                    stk.pop();
                }
                back=height[i];
            }
        }
        int temp;
        if(!stk.empty())
        temp=stk.top();
        while(!stk.empty())
        {
            if(stk.top()>temp)
            temp=stk.top();
            stk.pop();
            if(!stk.empty())
            {
                if(temp-stk.top()>0)
                    sum+=temp-stk.top();
            }
        }
        return sum;
    }
};