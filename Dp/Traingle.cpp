class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));

        dp[1][1] = nums[0][0];
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                if(j==1) dp[i][j] = dp[i-1][j] + nums[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]) + nums[i-1][j-1];
            }
        }

        int mini = INT_MAX;
       // cout<<dp[3][2]<<endl;
        for(int i=1;i<=n;i++)
        {
            mini = min(mini,dp[n][i]);
        }
        return mini;
    }
};