class Solution {
public:
    void bfs(vector<vector<int>>& isConnected,vector<bool>& visited,int index,int v)
    {
        visited[index]=true;
        for(int i=0;i<v;i++)
        {
            if(index!=i&&isConnected[index][i]&&!visited[i])
            {
                bfs(isConnected,visited,i,v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        int count=0;
        vector<bool> visited(v,false);
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                count++;
                bfs(isConnected,visited,i,v);
            }
        }
        return count;
    }
};