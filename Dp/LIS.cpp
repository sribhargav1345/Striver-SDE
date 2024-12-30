class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i=1;i<=n;i++)
        {
            if(i == 1 || nums[i-1]> ans.back()) ans.push_back(nums[i-1]);
            else
            {
                auto low = lower_bound(ans.begin(),ans.end(),nums[i-1]) - ans.begin();
                ans[low] = nums[i-1];
            }
        }
        return ans.size();
    }
};