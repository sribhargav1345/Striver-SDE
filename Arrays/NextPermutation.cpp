class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;

        int flag = 0;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            reverse(nums.begin(),nums.end());
            return;
        }

        int k;
        for(int j=n-1;j>i;j--)
        {
            if(nums[j]>nums[i])
            {
                k = j;
                break;
            }
        }

        cout<<i<<k<<endl;
        swap(nums[i],nums[k]);
        reverse(nums.begin()+i+1,nums.end());
    }
};