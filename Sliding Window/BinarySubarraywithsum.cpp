class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        map<int,int> mp;
        mp[0] = 1;

        int ans = 0,sum = 0;

        for(int i=0;i<n;i++)
        {
            sum += nums[i];

            if(mp.find(sum-goal) != mp.end()) ans += mp[sum-goal];
            mp[sum]++;
        }
        return ans;
    }
};