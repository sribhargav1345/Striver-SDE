#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

static bool compare(pair<ll,ll>& a,pair<ll,ll>& b){
    return a.second < b.second;
}

int main()
{
    ll n;
    cin>>n;

    vector<pair<ll,ll>> arr;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
    
        arr.push_back({x,y});
    }
    
    sort(arr.begin(),arr.end(),compare);

    ll sum = 0;
    ll ans = 0;

    for(int i=0;i<n;i++)
    {
        sum += arr[i].first;
        ans += (arr[i].second - sum);
    }

    cout<<ans<<endl;
}