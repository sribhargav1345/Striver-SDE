class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        map<char,int> mpt;
        map<char,int> mp;

        for(auto x:t) mpt[x]++;
        int maxi = INT_MAX;

        int p = -1;

        int i=0,j=0;
        while(j<n)
        {
            mp[s[j]]++;
            int flag = 0;
            for(auto x:mpt)
            {
                if(mp[x.first]<mpt[x.first]){
                    flag = 1;
                    break;
                }
            }

            if(flag == 0){
                while(mp[s[i]]>mpt[s[i]])
                {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }

                if(maxi > j-i+1){
                    maxi = j-i+1;
                    p = i;
                }
            }
            j++;
        }

        if(p == -1) return "";
        return s.substr(p,maxi);
    }
};