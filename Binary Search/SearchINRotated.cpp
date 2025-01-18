// 1
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<=high)
        {
            int mid = (low+high)/2;

            if(nums[low]<=nums[mid]){
                // This part is the sorted part
                if(nums[mid] == target) return mid;
                if(nums[mid]> target && nums[low]<=target){
                    high = mid - 1;
                }
                else low = mid + 1;
            }   
            else if(nums[mid]<nums[high])
            {
                // This part is the sorted part
                if(nums[mid] == target) return mid;
                if(nums[mid]<target && nums[high]>=target){
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }
        return -1;
    }
};

//2 
class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int n = arr.size();

        int low = 0;
        int high = n-1;

        while(low<=high)
        {
            int mid = (low+high)/2;

            if(arr[mid] == k) return true;

            if(arr[low] == arr[mid] && arr[mid] == arr[high])
            {
                low++;
                high--;

                continue;
            }

            if(arr[low] <= arr[mid])
            {
                if(arr[low]<k && k<arr[mid]) high = mid - 1;
                else if(arr[low] == k || arr[mid] == k) return true;
                else low = mid + 1;
            }
            else
            {
                if(arr[mid]<k && k<arr[high]) low = mid + 1;
                else if(arr[high] == k || arr[mid] == k) return true;
                else high = mid - 1;
            }
        }
        return false;
    }
};