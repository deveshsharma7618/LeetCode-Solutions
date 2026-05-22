class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n = s.size(), m = p.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        dp[0][0] = 1; // both empty

        for(int j = 1; j <= m; j++) {

            if(p[j - 1] == '*')

                dp[0][j] = dp[0][j - 1]; // * takes empty
        }

        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= m; j++) {

                if(p[j - 1] == '*') {

                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];

                    // skip * or use it for curr char
                }
                else if(p[j - 1] == '?' || s[i - 1] == p[j - 1]) {

                    dp[i][j] = dp[i - 1][j - 1];

                    // chars match
                }
            }
        }
        return dp[n][m];
    }
};
