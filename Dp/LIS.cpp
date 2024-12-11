class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            if(v.empty()){
                v.push_back(nums[i-1]);
            }
            else 
            {
                if(nums[i-1]>v.back()){
                    v.push_back(nums[i-1]);
                }
                else
                {
                    auto low = lower_bound(v.begin(),v.end(),nums[i-1]) - v.begin();
                    v[low] = nums[i-1];
                }
            }
        }
        return v.size();
    }
};