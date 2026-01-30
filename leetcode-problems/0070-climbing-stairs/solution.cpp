class Solution {
public:
    long long ncr(int n,int k) {
        if (k > n)
            return 0;
        if (k == 0 || k == n)
            return 1;

        long long res = 1;
        for (int i = 0; i < k; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
    int climbStairs(int n) {
        if (n == 0) {
            return 0;
        }
        int ans = 1;
        int i = n;
        for (int i = 1; i < n; i++) {
            int j = n - 2 * i;
            if (j >= 0) {
                ans += (int)ncr(n-i, i);
            }
        }
        return ans;
    }
};
