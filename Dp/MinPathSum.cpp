class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=m;i++)
        {
            dp[1][i] = grid[0][i-1] + dp[1][i-1]; 
        }
        for(int i=1;i<=n;i++)
        {
            dp[i][1] = grid[i-1][0] + dp[i-1][1]; 
        }

        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=m;j++)
            {
                dp[i][j] = min(dp[i-1][j] + grid[i-1][j-1], dp[i][j-1] + grid[i-1][j-1]);
            }
        }
        
        return dp[n][m];
    }
};