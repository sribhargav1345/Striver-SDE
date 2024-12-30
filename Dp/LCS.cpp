class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

// Print LCS
void printLCS(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    int len = longestCommonSubsequence(s1,s2);

    string ans = "";
    for(int i=0;i<len;i++) ans += '$';

    int index = len - 1;
    int i = n;j = m;

    while(i>=0 && j>=0) 
    {
        if(s1[i-1]==s2[j-1])
        {
            ans[index] = s1[i-1];
            index -= 1;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }

    cout<<ans<<endl;
}

// Print all LCS
class Solution {
  public:
    void solve(string s,string t,int i,int j,vector<vector<int>>& dp,set<string>& ans,string curr)
    {   
        if(i == 0 || j == 0){
            reverse(curr.begin(),curr.end());
            ans.insert(curr);
            
            return;
        }
        
        if(s[i-1] == t[j-1]){
            solve(s,t,i-1,j-1,dp,ans,curr + s[i-1]);
        }
        else{
            if(dp[i-1][j] == dp[i][j]){
                solve(s,t,i-1,j,dp,ans,curr);
            }
            if(dp[i][j-1] == dp[i][j]) solve(s,t,i,j-1,dp,ans,curr);
        }
    }
    
    vector<string> all_longest_common_subsequences(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        set<string> ans; 
        solve(s,t,n,m,dp,ans,"");
        
        return vector<string>(ans.begin(), ans.end());
    }
};