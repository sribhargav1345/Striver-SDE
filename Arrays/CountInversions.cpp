lass Solution {
  public:
    // Function to count inversions in the array.
    int merge(int low,int mid,int high,vector<int>& arr){
        int i = low;
        int j = mid + 1;
        
        vector<int> temp;
        int ct = 0;
        
        int cnt = 0;
        while(i <= mid && j <= high)
        {
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                cnt += (mid-i+1);
                j++;
            }
        }
        
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int k=0;k<temp.size();k++)
        {
            arr[low+k] = temp[k];
        }
        
        return cnt;
    }
    
    int mergeSort(int low,int high,vector<int>& arr){
        if(low >= high){
            return 0;
        }    
        
        int mid = (low+high)/2;
        
        int cnt = 0;
        cnt += mergeSort(low,mid,arr);
        cnt += mergeSort(mid+1,high,arr);
        
        cnt += merge(low,mid,high,arr);
        
        return cnt;
    }
    
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        
        return mergeSort(0,n-1,arr);
    }
};