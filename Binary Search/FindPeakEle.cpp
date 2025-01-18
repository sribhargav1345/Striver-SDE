class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int m = arr.size();

        if(m == 1) return 0;

        // They asked about logn time, so we have to use Binary search
        int low = 1;
        int high = m-2;

        if(arr[0]>arr[1]) return 0;
        if(arr[m-2]<arr[m-1]) return m-1;

        while(low<=high)
        {
            int mid = (low+high)/2;

            // Check if it's peak
            if(arr[mid-1]< arr[mid] && arr[mid+1]<arr[mid]){
                return mid;
            }

            if(arr[mid-1]<arr[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};