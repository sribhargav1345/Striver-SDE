class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> dp(n+1,0);
        
        dp[1] = arr[0];
        for(int i=2;i<=n;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                if(arr[i-1]>arr[j-1])
                {
                    dp[i] = max(dp[i],dp[j]+arr[i-1]);
                }
            }
            dp[i] = max(dp[i],arr[i-1]);
        }
        
        int maxi = 0;
        for(int i=1;i<=n;i++)
        {
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};