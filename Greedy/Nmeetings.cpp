class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
        
        sort(v.begin(),v.end());
        
        int cnt = 1;
        int prev = v[0].second;
        
        for(int i=1;i<n;i++)
        {
            if(v[i].first>prev)
            {
                cnt++;
                prev = v[i].second;
            }
            else prev = min(prev,v[i].second);
        }
        return cnt;
    }
};