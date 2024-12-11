class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // Kind of knapsack

        vector<vector<long>> dp(n+1,vector<long>(amount+1,INT_MAX));

        for(int i=0;i<=n;i++) dp[i][0] = 0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1] <= j)
                {
                    long take = dp[i][j-coins[i-1]] + 1;
                    long nottake = dp[i-1][j];

                    dp[i][j] = min(take,nottake);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        if(dp[n][amount] == INT_MAX) return -1;
        return dp[n][amount];
    }
};