class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;

        vector<int> v;
        int i=0,j=0;
        while(j<n)
        {
            while(!dq.empty() && nums[dq.back()]<nums[j])
            {
                dq.pop_back();
            }
            dq.push_back(j);

            if(j-i+1 == k){
                v.push_back(nums[dq.front()]);

                if(dq.front() == i) dq.pop_front();
                i++;
            }

            j++;
        }
        return v;
    }
};