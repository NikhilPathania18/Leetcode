class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int fh=-1,sh=-1;
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]>fh)
                fh=candies[i];
        }
        
        vector<bool> extra;
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]==fh)
                extra.push_back(true);
            
            else if(candies[i]+extraCandies>=fh)
                extra.push_back(true);
            else
                extra.push_back(false);
        }
        return extra;
    }
};