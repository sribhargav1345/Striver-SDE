class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = n-1;

        while(low<=high)
        {
            int mid = (low+high)/2;

            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] < target){
                if(matrix[mid][m-1] < target) low = mid+1;
                else 
                {
                    high = mid;
                    break;
                }
            }
            else high = mid - 1;
        }

        if(high<0) return false;
        int row = high;

        low = 0;
        high = m-1;

        while(low<=high)
        {
            int mid = (low+high)/2;

            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] < target){
                low = mid+1;
            }
            else high = mid - 1;
        }
        return false;
    }
};