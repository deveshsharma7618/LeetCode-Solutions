class Solution {
public:
    void interchange_row_and_column(vector<vector<int>> &matrix,int k){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            int temp = matrix[i][n-k-1];
            matrix[i][n-k-1] = matrix[k][i];
            matrix[k][i] = temp;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j =0;j<i;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j =0;j<columns/2;j++){
                int temp = matrix[i][columns-j-1];
                matrix[i][columns-j-1] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};
