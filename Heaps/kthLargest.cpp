class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;

        for(auto x:nums) pq.push(x);

        while(!pq.empty() && k>1)
        {
            pq.pop();
            k--;
        }
        if(!pq.empty()) return pq.top();
        return -1;
    }
};