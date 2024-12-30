/*
Amazon has multiple delivery centers and delivery warehouses all over the world The world is represented by a number line from -10^9 to 10^9 There are n delivery centers, the ith one at location center[i]. A location x is called a suitable location for a warehouse if it is possible to bring all the products to that point by traveling a distance of no more than d. At any one time, products can be brought from one delivery center and placed at point x. Given the positions of n delivery centers, calculate the number of suitable locations in the world, That is, calculate the number of points x on the number line (-109 < x < 109) where the travel distance required to bring all the products to that point is less than or equal to d. Note: The distance between point x and center[i] is |x- centerli]|, their absolute difference. Confidential
Example Given n= 3, center = [-2, 1, 0], d =8
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;

    vector<ll> arr;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
    
        arr.push_back(x);
    }
    
    ll d;
    cin>>d;

    sort(arr.begin(),arr.end());

    if(arr[n-1]-d<=arr[0]+d)
    {
        cout<<(arr[0]-arr[n-1]+2*d+1)<<endl;
    }
    else cout<<"NOT POSSIBLE"<<endl;
}