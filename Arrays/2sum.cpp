class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0,j = n-1;

        vector<pair<int,int>> v;
        for(int k=0;k<n;k++)
        {
            v.push_back({nums[k],k});
        }

        sort(v.begin(),v.end());

        vector<int> ans;
        while(i<=j)
        {
            if(v[i].first + v[j].first == target){
                ans.push_back(v[i].second);
                ans.push_back(v[j].second);

                return ans;
            }
            else if(v[i].first + v[j].first > target){
                j--;
            }
            else i++;
        }
        return ans;
    }
};