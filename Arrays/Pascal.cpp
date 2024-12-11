#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// If we want to find element at position (n,c) then ans = (n-1)C(c-1)
int nCr(int n,int c)
{
    int ans = 1;
    for(int i=0;i<c;i++)
    {
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}

// Print nth row
vector<int> generateRow(int row) {
    long long ans = 1;

    vector<int> ansRow;
    ansRow.push_back(1); 

    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

// Print all rows
vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}