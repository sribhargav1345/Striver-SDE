class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> odds(n,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i] % 2)
            {
                odds[i] += 1;
            }
            if(i>0) odds[i] += odds[i-1];
        }

        // now have to find same as sum-goal question
        map<int,int> mp;
        mp[0] = 1;

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            if(mp.find(odds[i]-k) != mp.end()) ans += mp[odds[i]-k];
            mp[odds[i]]++;
        }
        return ans;
    }
};