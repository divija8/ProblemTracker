class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, m = matrix.size(), n = matrix[0].size(), high = (m*n)-1;
        while(low <= high){
            int mid = (low+high)/2;
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] > target){
                high = mid-1;
            }else {
                low = mid+1;
            }

        }
        return false;
    }
};