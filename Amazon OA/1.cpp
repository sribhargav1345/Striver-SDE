#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin>>s;

    int n = s.size();

    string p = s;
    reverse(p.begin(),p.end());

    int i = 0,j = 0;
    while(i<n && j<n)
    {
        if(s[i] == p[j])
        {
            i++;
            j++;
        }
        else i++;
    }

    cout<<(n-j)<<endl;
}