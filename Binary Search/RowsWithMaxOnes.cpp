lass Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        
        int mini = m+1,k = -1;

        for(int i=0;i<n;i++)
        {
            int low = lower_bound(arr[i].begin(),arr[i].end(),1) - arr[i].begin();
            if(low<mini){
                mini = low;
                k = i;
            }
        }
        return k;
    }
};