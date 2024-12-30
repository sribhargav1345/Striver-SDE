class Solution {
  public:
  
    int f(vector<int>& stalls,int mid,int n,int k)
    {
        int prev = stalls[0];
        int ct = 1;
        
        for(int i=1;i<n;i++)
        {
            if(stalls[i]-prev >= mid)
            {
                ct++;
                prev = stalls[i];
            }
        }
        return (ct>=k);
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        
        sort(stalls.begin(),stalls.end());
        
        int low = 0;
        int high = stalls[n-1] - stalls[0];
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            
            if(f(stalls,mid,n,k)){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return high;
    }
};