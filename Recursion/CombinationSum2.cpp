class Solution {
public:
    void solve(int idx,vector<int>& nums,int n,int target,int sum,vector<vector<int>>& ans,vector<int>& v)
    {
        if(sum == target){
            ans.push_back(v);
            return;
        }

        for(int i=idx;i<n;i++)
        {
            if(i>idx && nums[i] == nums[i-1]){
                continue;
            }

            if(sum + nums[i]<=target)
            {
                v.push_back(nums[i]);
                solve(i+1,nums,n,target,sum+nums[i],ans,v);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> v;

        sort(nums.begin(),nums.end());

        solve(0,nums,n,target,0,ans,v);
        return ans;
    }
};