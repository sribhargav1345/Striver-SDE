#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n,vector<int>& arr)
{
    sort(arr.begin(),arr.end(),greater<int>());
    int k = -1;

    for(int i=0;i<n;i++)
    {
        if(arr[i]<=i+1)
        {
            k = i;
            break;
        }
    }
    if(k==-1) return k;

    map<int,int> mp;
    for(auto x:arr) mp[x]++;

    for(int i=k;i<n;i++)
    {
        int p = arr[i];
        int ct = 0;
        for(auto x:mp)
        {
            if(x.first%p == 0){
                ct++;
            }
        }

        if(ct == p){
            return ct;
        }
    }
    return -1;

}

int main()
{
    int n;
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
    
        arr.push_back(x);
    }

    cout<<solve(n,arr)<<endl;
}