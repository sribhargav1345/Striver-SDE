// Next permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int flag =0;
        int k;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                flag = 1;
                k = i;
                break;
            }
        }

        if(flag == 0){
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(int i=n-1;i>k;i--){
                if(nums[i]>nums[k]){
                    swap(nums[k],nums[i]);
                    break;
                }
            }
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};

// Prev permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int flag =0;
        int k;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){              // Sign change here
                flag = 1;
                k = i;
                break;
            }
        }

        if(flag == 0){
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(int i=n-1;i>k;i--){
                if(nums[i]<nums[k]){            // Sign change here
                    swap(nums[k],nums[i]);
                    break;
                }
            }
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};