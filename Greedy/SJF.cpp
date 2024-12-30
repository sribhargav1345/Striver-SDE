class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        long long ans = 0;
        long long sum = 0;
        
        sort(bt.begin(),bt.end());
        
        int n = bt.size();
        
        for(int i=0;i<n;i++)
        {
            ans += sum;
            sum += bt[i];
        }
        return (ans/n);
    }
};