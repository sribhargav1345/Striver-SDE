class Solution {
public:
    void solve(int idx,int n,vector<int>& nums,int target,int sum,vector<vector<int>>& ans,vector<int>& v)
    {
        if(idx == n){
            if(sum == target) ans.push_back(v);
            return;
        }

        if(sum + nums[idx] <= target){
            v.push_back(nums[idx]);
            solve(idx,n,nums,target,sum+nums[idx],ans,v);
            v.pop_back();
        }
        solve(idx+1,n,nums,target,sum,ans,v);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> v;

        solve(0,n,candidates,target,0,ans,v);
        return ans;
    }
};