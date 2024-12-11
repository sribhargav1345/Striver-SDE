#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n,string s)
{
    vector<int> freq(26,0);
    for(int i=0;i<n;i++)
    {
        freq[s[i]-'a']++;
    }

    int odd = 0;
    for(int i=0;i<26;i++)
    {
        if(freq[i]%2 != 0){
            odd++;
        }
    }

    if(odd<=1){
        cout<<0<<endl;
    }
    else
    {
        for(int i=0;i<26;i++)
        {
            char p = s[i] + 'a';
            vector<vector<int>> v(26);
            
            for(int j=0;j<n;j++)
            {
                if(s[j] != p)
                {
                    
                }
            }
        }
    }
}

int main()
{
    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        string s;
        cin>>s;

        solve(n,s);
    }
}