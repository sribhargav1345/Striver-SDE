class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int i,vector<int>& ans,vector<int>& visited,vector<vector<int>>& adj)
    {
        ans.push_back(i);
        visited[i] = 1;
        
        for(auto x:adj[i]){
            if(!visited[x]) dfs(x,ans,visited,adj);
        }
    }
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        
        vector<int> visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i]) dfs(i,ans,visited,adj);
        }
        return ans;
    }
};