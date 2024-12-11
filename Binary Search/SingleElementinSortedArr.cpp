class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = n-1;

        while(low<=high)
        {
            int mid = (low+high)/2;

            if(mid %2 == 0){
                if(mid<n-1 && nums[mid] == nums[mid+1]){
                    low = mid + 1;
                }
                else if(mid>0 && nums[mid] == nums[mid-1]){
                    high = mid - 1;
                }
                else return nums[mid];
            }
            else
            {
                if(mid>0 && nums[mid] == nums[mid-1]){
                    low = mid + 1;
                }
                else if(mid<n-1 && nums[mid] == nums[mid+1]){
                    high = mid - 1;
                }
                else return nums[mid];
            }
        }
        return -1;
    }
};