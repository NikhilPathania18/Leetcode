class Solution {
public:
    void dfs(vector<vector<int>>& adj,int index,vector<bool>& visited)
    {
        visited[index]=true;
        for(int i=0;i<adj[index].size();i++)
        {
            if(!visited[adj[index][i]])
                dfs(adj,adj[index][i],visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int v=rooms.size();
        vector<bool> visited(v,false);
        dfs(rooms,0,visited);
        for(int i=0;i<v;i++)
            if(!visited[i]) return false;
        return true;
    }
};