class Solution {
public:
    bool dfs(vector<vector<int>> &adj,int index,int destination,vector<bool>& visited,int prev)
    {
        if(index==destination)  return true;
        if(!visited[index])
        {
            visited[index]=true;
            for(int i=0;i<adj[index].size();i++)
            {
                if(adj[index][i]==prev)
                    continue;
                if(dfs(adj,adj[index][i],destination,visited,index))  return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(adj,source,destination,visited,-1);
    }
};