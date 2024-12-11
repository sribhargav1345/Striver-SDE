class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        queue<int> q;
        
        vector<int> ans;
        q.push(0);
        
        vector<int> visited(n,0);
        
        while(!q.empty())
        {
            auto itr = q.front();
            q.pop();
            
            if(visited[itr] == 0)
            {
                ans.push_back(itr);
                visited[itr] = 1;   
            }
            
            for(auto it:adj[itr])
            {
                if(!visited[it]){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};