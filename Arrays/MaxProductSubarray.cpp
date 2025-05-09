class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

        int pro = 1;
        for(int i=0;i<n;i++)
        {
            pro = pro*nums[i];
            maxi = max(maxi,pro);

            if(pro == 0) pro = 1;
        }

        pro = 1;
        for(int i=n-1;i>=0;i--)
        {
            pro = pro*nums[i];
            maxi = max(maxi,pro);
            
            if(pro == 0) pro = 1;
        }
        return maxi;
    }
};