class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n < 0) {
            return 0;
        }

        if (dp[n] == -1) {
            return dp[n] = solve(n - 1,dp) + solve(n - 2, dp);
        }
        return dp[n];
    }
    int climbStairs(int n) {
        int ans = 0;
        vector<int> dp(n + 1, -1);
        if (n < 1) {
            return 0;
        } else if (n <= 2) {
            return n;
        }
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        solve(n, dp);
        return dp[n];
    }
};