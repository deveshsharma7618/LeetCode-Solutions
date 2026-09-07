class Solution {
public:
    int MOD = 1000000007;

    int distinctSubseqII(string s) {
        int tot = 0;
        int dp[26];

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 97;
            int add = (tot - dp[c] + MOD) % MOD;

            dp[c] = 1 + tot;
            tot = (dp[c] + add) % MOD;
        }

        return tot;
    }
};
