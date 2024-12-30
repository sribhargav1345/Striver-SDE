class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0]; 
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n+1,0);

        dp[1] = nums[0];
        for(int i=2;i<=n-1;i++)
        {
            dp[i] = max(dp[i-2]+nums[i-1],dp[i-1]);
        }

        int maxi = dp[n-1];

        vector<int> dp1(n+2,0);
        dp1[n] = nums[n-1];

        for(int i=n-1;i>=2;i--)
        {
            dp1[i] = max(dp1[i+2]+nums[i-1], dp1[i+1]);
        }

        maxi = max(maxi,dp1[2]);
        return maxi;
    }
};