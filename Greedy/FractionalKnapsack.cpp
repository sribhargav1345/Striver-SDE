class Solution {
  public:
    static bool compare(pair<int,int>& a,pair<int,int>& b)
    {
        double oa = (double)(a.first)/(double)(a.second);  
        double ob = (double)(b.first)/(double)(b.second);
        
        return (oa>ob);
    }
    
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        int n = val.size();
        
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({val[i],wt[i]});
        }
        
        sort(v.begin(),v.end(),compare);
        double ans = 0;
        
        int sum = 0;
        
        for(int i=0;i<n;i++)
        {
            if(sum + v[i].second <= capacity)
            {
                ans += v[i].first;
                sum += v[i].second;
            }
            else
            {
                ans += ((double)(v[i].first)/(double)(v[i].second))*(capacity-sum);
                break;
            }
        }
        return ans;
    }
};