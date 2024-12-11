class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int low = j+1;
                int high = n-1;

                long a = nums[i] + nums[j];

                while(low < high)
                {
                    if(a + nums[low] + nums[high] == target){
                        v.push_back(nums[i]);
                        v.push_back(nums[j]); 
                        v.push_back(nums[low]); 
                        v.push_back(nums[high]); 

                        if(find(ans.begin(),ans.end(),v) == ans.end()) ans.push_back(v);
                        v.clear();

                        low++;
                        high--;
                    }  
                    else if(a + nums[low] + nums[high] > target)
                    {
                        high--;
                    }
                    else low++;
                }
            }
        }
        return ans;
    }
};