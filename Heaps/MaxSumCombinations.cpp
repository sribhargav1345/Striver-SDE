vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int> arr(C,0);
    int n = A.size();
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            pq.push(A[i] + B[j]);   
        }
    }
    
    int i = 0;
    while(!pq.empty() && i<C)
    {
        auto p = pq.top();
        arr[i] = p;
        
        pq.pop();
        i++;
    }
    return arr;
}
