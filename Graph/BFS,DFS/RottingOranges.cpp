class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }

        vector<vector<int>> dup = grid;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        int t = 0;

        while(!q.empty())
        {
            auto itr = q.front();
            q.pop();

            int r = itr.first.first;
            int c = itr.first.second;

            int time = itr.second;
            t = time;

            visited[r][c] = 1;
            
            for(int k=0;k<4;k++)
            {
                int newr = r + dr[k];
                int newc = c + dc[k];

                if(newr>=0 && newc>=0 && newr<n && newc<m && dup[newr][newc] ==1 && visited[newr][newc] == 0)
                {
                    dup[newr][newc] = 2;
                    q.push({{newr,newc},time+1});
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dup[i][j] == 1) return -1; 
            }
        }
        return t;
    }
};