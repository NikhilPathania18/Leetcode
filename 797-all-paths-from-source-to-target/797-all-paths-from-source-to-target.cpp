class Solution {
public:
    void dfs(vector<vector<int>>& ans,vector<int>& path,vector<vector<int>>& adj,int index,int destination)
    {
        if(index==destination)
        {
            path.push_back(index);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(index);
        for(int i=0;i<adj[index].size();i++)
        {
            dfs(ans,path,adj,adj[index][i],destination);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int destination=graph.size()-1;
        vector<vector<int>> ans;
        vector<int> path;
        dfs(ans,path,graph,0,destination);
        return ans;
    }
};