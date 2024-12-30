vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        vector<int> ans;
        int n = adj.size();
            
        queue<int> q;
        vector<int> indegree(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(auto x:adj[i]){
                indegree[x]++;
            }
        }
        
        for(int i=0;i<n;i++) 
        {
            if(indegree[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }
        
        while(!q.empty())
        {
            auto itr = q.front();
            q.pop();
            
            for(auto x:adj[itr]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }