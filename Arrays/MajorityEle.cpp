// Moore's voting algo
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0,ele = 0;
        for(int i=0;i<n;i++)
        {
            if(ele == nums[i]){
                cnt++;
            }
            else
            {
                if(cnt>0) cnt--;
                else 
                {
                    cnt++;
                    ele = nums[i];
                }
            }
        }

        cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == ele) cnt++;
        }
        if(2*cnt>n) return ele;
        return -1;
    }
};