int f(int mid,int n,int m){
  long long p = 1;
  for(int j=0;j<n;j++)
  {
    p = p*mid;
    
    if(p>m){
      return 2;
    }
  }
  if(p == m) return 1;
  return 0;
}

int NthRoot(int n, int m) {
  int low = 1;
  int high = m;

  int ans = -1;

  while(low <= high)
  {
    int mid = (low+high)/2;

    if(f(mid,n,m) == 1){
      return mid;
    }
    if(f(mid,n,m) == 0){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }

  return ans;
}