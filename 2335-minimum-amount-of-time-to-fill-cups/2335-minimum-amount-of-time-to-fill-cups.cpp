class Solution {
public:
    int fillCups(vector<int>& amount) {
        int time=0;
        while(amount[0]>0||amount[1]>0||amount[2]>0)
        {
            sort(amount.begin(),amount.end(),greater<>());
            amount[0]--;
            amount[1]--;
            time++;
        }
        return time;
    }
};