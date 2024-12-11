class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        int i = 0,j = 0;
        map<int,int> mp;

        int ans = 0;

        while(j<n)
        {
            mp[s[j]]++;
            if(mp[s[j]]>1)
            {
                while(mp[s[j]]>1 && i<=j)
                {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};