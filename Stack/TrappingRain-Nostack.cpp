class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // Min(Rightmost great, Leftmost great) gives the answer i guess

        vector<int> lg(n,0);
        vector<int> rg(n);

        for(int i=n-2;i>=0;i--)
        {
            rg[i] = max(rg[i+1],height[i+1]);
        }

        for(int i=1;i<n;i++)
        {
            lg[i] = max(lg[i-1],height[i-1]);
        }

        int ans = 0;
        for(int i=1;i<n-1;i++)
        {
            if(lg[i]>height[i] && rg[i]>height[i]){
                ans += (min(lg[i],rg[i]) - height[i]);
            }
        }
        return ans;
    }
};

// Optimised, 2 pointer
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int left = 0;
        int right = n-1;

        int maxl = 0,maxr = 0;
        int ans = 0;
        while(left <= right)
        {
            if(height[left] <= height[right]){
                if(height[left]>=maxl){
                    maxl = height[left];
                }
                else ans += (maxl-height[left]);
                left++;
            }
            else
            {
                if(height[right]>=maxr){
                    maxr = height[right];
                }
                else ans += (maxr - height[right]);
                right--;
            }
        }
        return ans;
    }
};