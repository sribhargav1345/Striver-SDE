class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

        int sum = 0;

        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            maxi = max(maxi,sum);

            if(sum<0) sum = 0;
        }
        return maxi;
    }
};

class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN; 
        int sum = 0; 

        int start = 0; 
        int end = 0;   
        int tempStart = 0; 

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (sum > maxi) {
                maxi = sum;
                start = tempStart;
                end = i; 
            }

            if (sum < 0) {
                sum = 0;
                tempStart = i + 1; 
            }
        }

        // Extract the maximum subarray
        vector<int> result;
        for (int i = start; i <= end; i++) {
            result.push_back(nums[i]);
        }
        return result;
    }
};
