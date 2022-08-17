class Solution {
public:
    bool bfs(vector<vector<int>>& adj,vector<int> &visited,int index)
    {
        queue<int> q;
        q.push(index);
        visited[index]=0;
        while(!q.empty())
        {
            int front=q.front();
            for(int i=0;i<adj[front].size();i++)
            {
                if(visited[adj[front][i]]==-1)
                {
                    if(visited[front])  visited[adj[front][i]]=0;
                    else visited[adj[front][i]]=1;
                    q.push(adj[front][i]);
                }
                else if(visited[front]==visited[adj[front][i]])  return false;
            }
            q.pop();
        }
        return true;
    }
    bool dfs(vector<vector<int>>& adj,vector<int>& visited,int index)
    {
        for(int i=0;i<adj[index].size();i++)
        {
            if(visited[adj[index][i]]==-1)
            {
                if(visited[index]==0)
                    visited[adj[index][i]]=1;
                else visited[adj[index][i]]=0;
                if(!dfs(adj,visited,adj[index][i])) return false;
            }
            else if(visited[adj[index][i]]==visited[index])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(visited[i]==-1)
            {
                visited[i]=0;
                if(!dfs(graph,visited,i)) return false;
            }
        }
        return true;
    }
};