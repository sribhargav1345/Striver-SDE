int f(vector<int>& A,int mid,int B,int n){
    int sum = 0;
    int ct = 1;
    
    for(int i=0;i<n;i++)
    {
        if(sum + A[i] <= mid){
            sum += A[i];
        }
        else{
            ct++;
            sum = A[i];
        }
        
        if(ct>B) return false;
    }
    return (ct<=B);
}

int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    
    if(B>n) return -1;
    
    int low = *max_element(A.begin(),A.end());
    int high = 0;
    
    for(auto x:A) high += x;
    
    while(low<=high)
    {
        int mid = (low+high)/2;
        
        if(f(A,mid,B,n)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
