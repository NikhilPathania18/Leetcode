class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a,b;
        a=edges[0][0];
        b=edges[0][1];
        if(edges[1][0]==a)
            return a;
        if(edges[1][0]==b)
            return b;
        else return edges[1][1];
    }
};