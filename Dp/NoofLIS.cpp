class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,1);
        vector<int> cnt(n+1,1);

        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                if(nums[i-1]>nums[j-1])
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i] == dp[j]+1)
                    {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }  

        int maxi = 0, max_cnt = 0;
        for(int i=1;i<=n;i++)
        {
            maxi = max(dp[i],maxi);
        }

        for(int i=1;i<=n;i++)
        {
            if(dp[i]==maxi)
            {
                max_cnt += cnt[i];
            }
        }
        return max_cnt;
    }
};