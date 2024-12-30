// Reverse edges and topo

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[graph[i][j]].push_back(i);
            }
        }

        queue<int> q;
        vector<int> indegree(n,0);

        vector<int> ans;

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

            for(auto x:adj[itr])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                {
                    q.push(x);
                    ans.push_back(x);
                }
            }
        }
        sort(ans.begin(),ans.end());

        return ans;
    }
};