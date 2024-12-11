class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int mini = INT_MAX;
        int pro = 0;

        for(int i=0;i<n;i++)
        {
            pro = max(pro,prices[i]-mini);

            mini = min(mini,prices[i]);
        }
        return pro;
    }
};