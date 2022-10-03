class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time=0;
        int size=colors.size();
        for(int i=0;i<size-1;)
        {
            int currTime=0;
            
            if(colors[i]==colors[i+1])
            {
                int maxTime=neededTime[i];
                while(i<size-1&&colors[i]==colors[i+1])
                {
                    currTime+=neededTime[i];
                    if(neededTime[i]>maxTime)
                        maxTime=neededTime[i];
                    i++;
                }
                currTime+=neededTime[i];
                if(neededTime[i]>maxTime)
                    maxTime=neededTime[i];
                currTime-=maxTime;
                time+=currTime;
            }
            else    i++;
        }
        return time;
    }
};