lass Solution {
  public:
    bool f(vector<int>& stations,double mid,int k){
        int n = stations.size();
        
        int cnt = 0;
        for(int i=1;i<n;i++)
        {
            int op = ceil((stations[i]-stations[i-1]) / mid);
    
            op -= 1;
            cnt += op;
            
            if(cnt>k) return true;
        }
        return false;
    }
    
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        double ans = 0;
        int n = stations.size();
        
        sort(stations.begin(),stations.end());
        
        double low = 0;
        double high = stations[n-1] - stations[0];
        
        while(high - low >= 1e-6)
        {
            double mid = (low+high)/2.0;
            
            if(f(stations,mid,k)){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return high;
    }