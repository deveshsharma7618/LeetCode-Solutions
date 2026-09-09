class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long x = 1;        // Number of commas for the current range
        long long lower = 1000; // First number to receive 'x' commas

        while (lower <= n) {
            // Find the upper bound for the current number of commas
            long long upper = lower * 1000 - 1;

            if (n <= upper) {
                // n falls inside the current bracket
                ans += x * (n - lower + 1);
            } else {
                // The entire bracket fits below n
                ans += x * (upper - lower + 1);
            }

            x++;
            lower *= 1000; // Move to the next comma tier
        }
        return ans;
    }
};
