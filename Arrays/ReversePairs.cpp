class Solution {
public:
    int countReverse(int low, int mid, int high, vector<int>& nums) {
        int cnt = 0;
        int j = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - mid - 1);
        }

        return cnt;
    }

    int merge(int low,int mid,int high,vector<int>& nums){
        int i = low,j = mid+1;
        vector<int> temp;

        int cnt = 0;

        while(i<=mid && j<=high)
        {
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }

        for(int k=0;k<temp.size();k++){
            nums[low+k] = temp[k];
        }

        return cnt;
    }

    int mergeSort(int low,int high,vector<int>& nums){
        if(low >= high){
            return 0;
        }

        int cnt = 0;
        int mid = (low+high)/2;

        cnt += mergeSort(low,mid,nums);
        cnt += mergeSort(mid+1,high,nums);

        cnt += countReverse(low,mid,high,nums);
        merge(low,mid,high,nums);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(0,n-1,nums);
    }
};