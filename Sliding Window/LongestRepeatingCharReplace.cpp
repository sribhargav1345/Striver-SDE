class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxi = 0;
        
        for(int l=0;l<26;l++)
        {
            char c = static_cast<char>(65+l);

            int i = 0,j = 0;
            int p = 0;

            while(j<n)
            {
                if(s[j] != c){
                    p++;
                    while(p>k)
                    {
                        if(s[i] != c){
                            p--;
                        }
                        i++;
                    }
                }
                maxi = max(maxi,j-i+1);
                j++;
            }
        }
        return maxi;
    }
};