
// Most important is the base case of true condition
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
        
        for(int i=0;i<=n;i++) dp[i][0] = true;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(arr[i-1]<=j){
                    bool take = dp[i-1][j-arr[i-1]];
                    bool nottake = dp[i-1][j];
                    
                    dp[i][j] = take | nottake;
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }
};