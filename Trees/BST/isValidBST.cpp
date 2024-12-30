class Solution {
  public:
    bool isSorted(vector<int>& arr)
    {
        int n = arr.size();
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]>=arr[i]) return false;
        }
        return true;
    }
    
    bool isBSTTraversal(vector<int>& arr) {
        // your code here
        if(isSorted(arr)) return true;
        return false;
    }
};