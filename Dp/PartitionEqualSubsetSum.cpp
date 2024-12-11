class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum%2 != 0) return false;

        int k = sum/2;

        vector<vector<bool>> dp(n+1,vector<bool>(k+1,false));

        dp[0][0] = true;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(nums[i-1] <= j)
                {
                    int take = dp[i-1][j-nums[i-1]];
                    int nottake = dp[i-1][j];

                    dp[i][j] = take | nottake;
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][k];
    }
};