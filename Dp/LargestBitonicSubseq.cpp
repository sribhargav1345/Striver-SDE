class Solution {
  public:
    vector<int> solve(int n,vector<int>& nums){
        vector<int> dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        return dp;
    }
    
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> inc = solve(n,nums);
        
        vector<int> v = nums;
        reverse(v.begin(),v.end());
        
        vector<int> dec = solve(n,v);
        reverse(dec.begin(),dec.end());
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(inc[i] != 1 && dec[i] != 1) ans = max(ans,inc[i] + dec[i] - 1);      // not to count 1's since it should contain both inc and dec
        }
        return ans;
    }
};