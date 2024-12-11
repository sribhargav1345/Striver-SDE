#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
  public:
    void solve(int idx,int n,vector<int>& arr,vector<int>& ans,int sum){
        if(idx == n){
            ans.push_back(sum);
            return;
        }    
        
        solve(idx+1,n,arr,ans,sum+arr[idx]);
        solve(idx+1,n,arr,ans,sum);
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        
        vector<int> ans;
        int n = arr.size();
        
        solve(0,n,arr,ans,0);
        return ans;
    }
};