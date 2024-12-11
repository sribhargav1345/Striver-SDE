class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;
        vector<int> v;

        v.push_back(intervals[0][0]);
        int prev = intervals[0][1];

        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=prev)
            {
                prev = max(prev,intervals[i][1]);
            }
            else
            {
                v.push_back(prev);
                ans.push_back(v);

                v.clear();
                v.push_back(intervals[i][0]);
                prev = intervals[i][1];
            }
        }
        v.push_back(prev);
        ans.push_back(v);

        return ans;
    }
};