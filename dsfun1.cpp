#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        int r = arr[i];
        int sum = 0;
        while(r>0)
        {
            sum += (r%10);
            r /= 10;
        }

        cout<<sum<<" ";
    }
    cout<<endl;

}