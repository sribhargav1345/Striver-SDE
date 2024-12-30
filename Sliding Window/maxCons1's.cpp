class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();

        int i = 0,j = 0;
        int op = 0; 
        int maxi = 0;

        while(j<n)
        {
            if(arr[j] == 0)
            {
                op++;
            }

            while(op>k && i<=j)
            {
                if(arr[i] == 0){
                    op--;
                }
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;       
    }
};