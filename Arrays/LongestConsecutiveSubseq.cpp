class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        map<int,int> mp;

        for(int i=0;i<n;i++) mp[nums[i]] = 1;

        int ct = 1;
        int maxi = 1;

        for(auto x:mp)
        {
            if(mp.find(x.first-1)!=mp.end())
            {
                ct++;
                maxi = max(maxi,ct);
            }
            else ct = 1;
        }
        return maxi;
    }
};