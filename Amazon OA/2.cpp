/*
Amazon has a cluster of n servers. Some are in the OFF state while others are ON. The developers responsible for maintaining the servers have access to a special operation to change the states. In one operation, they can choose a contiguous sequence of servers and flip their states, i.e., ON to OFF and vice versa. Due to operational constraints, this operation can be performed on the cluster a maximum of k times.
Given a binary string server_states, of length n, where '1' represents ON, '0' represents OFF, and an integer k, find the maximum possible number of consecutive ON servers after at most k operations.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin>>s;

    ll k;
    cin>>k;

    int n = s.size();

    int i = 0;
    int j = 0;

    int ct = 0;
    int p = 0;

    while(j<n)
    {
        if(s[j] == '0')
        {
            if(ct == 0) 
            {
                p++;
                ct++;
            }
            else ct++;
        }
        else 
        {
            ct = 0;
        }

        if(p>k)
        {
            while(p>k && arr[i]=='0'){

            }
        }
    }
}