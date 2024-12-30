class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j==0){
                    dp[i][j] = max(dp[i-1][j+1],dp[i-1][j+2]) + arr[i-1][j];
                }
                if(j==1){
                    dp[i][j] = max(dp[i-1][j+1],dp[i-1][j-1]) + arr[i-1][j];
                }
                if(j==2){
                    dp[i][j] = max(dp[i-1][j-1],dp[i-1][j-2]) + arr[i-1][j];
                }
            }
        }
        
        return max({dp[n][1],dp[n][2],dp[n][0]});
    }
};