class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        long long total = 0;

        // total sum
        for (auto &row : grid) {
            for (int val : row) {
                total += val;
            }
        }

        // if total is odd → impossible
        if (total % 2 != 0) return false;

        long long curr = 0;

        // horizontal cut
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                curr += grid[i][j];
            }
            if (curr * 2 == total) return true;
        }

        // vertical cut
        curr = 0;
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                curr += grid[i][j];
            }
            if (curr * 2 == total) return true;
        }

        return false;
    }
};
