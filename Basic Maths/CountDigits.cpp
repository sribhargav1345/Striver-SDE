#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int evenlyDivides(int n) {
    // code here
    int r = n;
    int ct = 0;
    while(r>0)
    {
        int rem = r%10;
        if(rem != 0 && n%rem == 0){
            ct++;
        }
        
        r = r/10;
    }
    return ct;
}