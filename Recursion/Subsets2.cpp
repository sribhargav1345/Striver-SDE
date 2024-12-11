class Solution {
public:
    void solve(int idx, int n, vector<int>& nums, vector<int>& v, vector<vector<int>>& ans) {
        ans.push_back(v);

        // You have to handle duplicates like this -> If you use for loop, there is no base case of if(idx==n) remember
        for (int i = idx; i < n; ++i) {
            if (i > idx && nums[i] == nums[i-1]) {
                continue;
            }
            
            v.push_back(nums[i]);  
            solve(i + 1, n, nums, v, ans);  
            v.pop_back();  
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ans;
        vector<int> v;
        solve(0, nums.size(), nums, v, ans);
        return ans;
    }
};
