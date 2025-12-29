class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();

        int start = 0;
        int end = rows-1;
        int target_row = -1;
        while(start <= end){
            int mid = start + (end - start )/2;
            if(matrix[mid][0] <= target && matrix[mid][columns-1] >= target){
                target_row = mid;
                break;
            }else if(matrix[mid][0] > target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }

        if(target_row == -1)
            return false;

        start = 0;
        end = columns-1;
        while(start <= end){
            int mid = start + (end - start )/2;
            if(matrix[target_row][mid] < target){
                start = mid+1;
            }else if(matrix[target_row][mid] > target){
                end = mid-1;
            }else{
                return true;
            }
        }

        return false;
    }
};
