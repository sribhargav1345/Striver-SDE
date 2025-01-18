class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;

        for(int i=0;i<n;i++)
        {
            int a = nums[i];

            int low = i+1;
            int high = n-1;

            while(low < high)
            {
                int sum = nums[low] + nums[high];
                if(sum + a > 0){
                    high -= 1;
                }
                else if(sum + a < 0){
                    low += 1;
                }
                else
                {
                    vector<int> triplet = {a, nums[low], nums[high]};
                    ans.push_back(triplet);

                    while(low < high && nums[low] == triplet[1]) low++;
                    while(low < high && nums[high] == triplet[2]) high--;
                }
            }

            while(i+1 < n && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};