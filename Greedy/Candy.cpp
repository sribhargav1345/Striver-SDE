class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1]){
                left[i] = left[i-1] + 1;
            }
        }

        vector<int> right(n,1);
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1]){
                right[i] = right[i+1] + 1;
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += max(left[i],right[i]);
        } return ans;
    }
};

// If asked in O(1) space, you need this:
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;

        int candy = n;      // Everyone get one candy atleast
        while(i<n)
        {
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            int peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                candy += peak;
                i++;

                if(i == n){
                    return candy;
                }
            }

            int valley = 0;
            while(i<n && ratings[i]<ratings[i-1]){
                valley++;
                candy += valley;
                i++;
            }

            candy -= min(peak,valley);
        }
        return candy;
    }
};