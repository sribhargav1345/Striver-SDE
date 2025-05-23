class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int ans = 1;
        int maxi = INT_MIN;

        for(int i=0;i<n;i++)
        {
            ans = ans*nums[i];
            maxi = max(maxi,ans);

            if(ans == 0) ans = 1;
        }

        ans = 1;
        for(int i=n-1;i>=0;i--)
        {
            ans = ans*nums[i];
            maxi = max(maxi,ans);

            if(ans == 0) ans = 1;
        }
        return maxi;
    }
};