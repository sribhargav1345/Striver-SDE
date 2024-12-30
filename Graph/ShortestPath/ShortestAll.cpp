// Undirected
vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    queue<pair<int,int>> q;
    q.push({0,src});
    
    int n = adj.size();
    vector<int> ans(n,-1);
    
    vector<int> vis(n,0);
    
    while(!q.empty())
    {
        auto itr = q.front();
        q.pop();
        
        vis[itr.second] = 1;
        ans[itr.second] = itr.first;
        
        for(auto x:adj[itr.second]){
            if(!vis[x]){
                vis[x] = 1;
                q.push({itr.first+1,x});
            }
        }
    }
    return ans;
}

// Directed Acyclic
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
    vector<vector<pair<int,int>>> adj(V);
    for(int i=0;i<E;i++)
    {
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    
    vector<int> dist(V,INT_MAX);
    dist[0] = 0;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    
    
    while(!pq.empty())
    {
        auto itr = pq.top();
        pq.pop();
        
        for(auto x:adj[itr.second]){
            if(dist[x.first] > dist[itr.second] + x.second){
                dist[x.first] = dist[itr.second] + x.second;
                pq.push({dist[x.first],x.first});
            }
        }
    }
    
    for(int x=0;x<V;x++){
        if(dist[x] == INT_MAX) dist[x] = -1;
    }
    return dist;
}

// Dijsktra
class Solution
{
	public:
    vector<int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});
        
        vector<int> dist(n,INT_MAX);
        dist[s] = 0;
        
        while(!pq.empty())
        {
            auto itr = pq.top();
            pq.pop();
            
            int dis = itr.first;
            int node = itr.second;
            
            for(auto it: adj[node])
            {
                if(dist[it[0]]>dis + it[1])
                {
                    dist[it[0]] = dis + it[1];
                    pq.push({dist[it[0]],it[0]});
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(dist[i]==INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};