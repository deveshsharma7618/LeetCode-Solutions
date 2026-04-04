class Solution {
public:
    static const int MAXX = 1024; // depends on constraints

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bitset<MAXX>>> dp(m, vector<bitset<MAXX>>(n));

        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) continue;

                bitset<MAXX> curr;

                if (i > 0) {
                    for (int x = 0; x < MAXX; x++) {
                        if (dp[i-1][j][x]) {
                            curr[x ^ grid[i][j]] = 1;
                        }
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < MAXX; x++) {
                        if (dp[i][j-1][x]) {
                            curr[x ^ grid[i][j]] = 1;
                        }
                    }
                }

                dp[i][j] = curr;
            }
        }

        for (int x = 0; x < MAXX; x++) {
            if (dp[m-1][n-1][x]) return x;
        }

        return -1; // should not happen normally
    }
};
