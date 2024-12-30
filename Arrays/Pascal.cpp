class Solution {
public:
    int comb(int n,int m){
        // Find nCm
        if(m==0 || m==n) return 1;
        int res = 1;
        for(int i=0;i<m;i++)
        {
            res *= (n-i);
            res /= (i+1);
        }
        return res;
    }
    
    vector<int> generateRows(int n){
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            v.push_back(comb(n-1,i-1));
        }
        return v;
    }

    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++)
        {
            ans.push_back(generateRows(i));
        }
        return ans;
    }
};