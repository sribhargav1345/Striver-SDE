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

// n/3
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0,cnt2 = 0;
        int el1 = INT_MIN,el2 = INT_MIN;

        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(cnt1 == 0 && nums[i] != el2){
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != el1){
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(el1 == nums[i]){
                cnt1++;
            }
            else if(el2 == nums[i]){
                cnt2++;
            }
            else 
            {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ls;
        cnt1 = 0,cnt2 = 0;
        for(int i=0;i<n;i++)
        {
            if(el1 == nums[i]) cnt1++;
            if(el2 == nums[i]) cnt2++;
        }

        int mini = (int)(n/3) + 1;
        if(cnt1 >= mini) ls.push_back(el1);
        if(cnt2 >= mini) ls.push_back(el2);

        return ls;
    }
};