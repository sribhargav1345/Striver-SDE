class Solution {
public:
    int solve(int idx,int n,vector<int>& prices,int buy,int k,vector<vector<vector<int>>>& dp){
        if(idx == n || k == 0){
            return 0;
        }

        if(dp[idx][buy][k] != -1){
            return dp[idx][buy][k];
        }

        int profit;
        if(buy == 0){
            profit = max(-prices[idx] + solve(idx+1,n,prices,1,k,dp), solve(idx+1,n,prices,0,k,dp));
        }
        else{
            profit = max(prices[idx] + solve(idx+1,n,prices,0,k-1,dp), solve(idx+1,n,prices,1,k,dp));
        }
        
        return dp[idx][buy][k] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));

        return solve(0,n,prices,0,k,dp);
    }
};