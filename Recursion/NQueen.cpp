class Solution {
public:
    bool isValid(int r,int c,vector<string>& v,int n){
        for(int i=0;i<n;i++){
            if(i != r){
                if(v[i][c] == 'Q') return false;
            }
            if(i != c){
                if(v[r][i] == 'Q') return false;
            }
        }

        int dupr = r;
        int dupc = c;

        while(dupr>=0 && dupc>=0){
            if(v[dupr][dupc] == 'Q'){
                return false;
            }
            dupr--;
            dupc--;
        }

        dupr = r;
        dupc = c;
        while(dupr>=0 && dupc<n){
            if(v[dupr][dupc] == 'Q'){
                return false;
            }
            dupr--;
            dupc++;
        }

        dupr = r;
        dupc = c;
        while(dupr<n && dupc>=0){
            if(v[dupr][dupc] == 'Q'){
                return false;
            }
            dupr++;
            dupc--;
        }

        dupr = r;
        dupc = c;
        while(dupr<n && dupc<n){
            if(v[dupr][dupc] == 'Q'){
                return false;
            }
            dupr++;
            dupc++;
        }
        return true;
    }

    void solve(int idx,int n,vector<string>& v,vector<vector<string>>& ans){
        if(idx == n){
            ans.push_back(v);
            return;
        }

        for(int j=0;j<n;j++){
            if(isValid(idx,j,v,n)){
                v[idx][j] = 'Q';
                solve(idx+1,n,v,ans);
                v[idx][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v;

        for(int i=0;i<n;i++)
        {
            string p = "";
            for(int j=0;j<n;j++) p += '.';

            v.push_back(p);
        }

        solve(0,n,v,ans);
        return ans;
    }
};