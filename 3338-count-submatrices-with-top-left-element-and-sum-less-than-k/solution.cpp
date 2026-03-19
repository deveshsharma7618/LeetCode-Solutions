class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> sum(rows, vector<int>(cols, 0));

        sum[0][0] = grid[0][0];

        // first row
        for(int j = 1; j < cols; j++){
            sum[0][j] = sum[0][j-1] + grid[0][j];
        }

        // first column
        for(int i = 1; i < rows; i++){
            sum[i][0] = sum[i-1][0] + grid[i][0];
        }

        // rest
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                sum[i][j] = grid[i][j]
                          + sum[i-1][j]
                          + sum[i][j-1]
                          - sum[i-1][j-1];
            }
        }

        int ans = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(sum[i][j] <= k){
                    ans++;
                }
            }
        }

        return ans;
    }
};
