class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = (nums[0] == 1) ? 1 : 0; // Handles n = 1 edge case

        // Since nums[i] <= 10 (in standard problem constraints), 
        // the max possible LCM of all elements <= 2520.
        // We set a safe ceiling to avoid overflow.
        long long MAX_VAL = 1e15; 

        for (int i = 0; i < n; i++) {
            long long prod = nums[i];
            long long g = nums[i];
            long long l = nums[i];

            if (prod == g * l) {
                ans = max(ans, 1);
            }

            for (int j = i + 1; j < n; j++) {
                // Prevent overflow before multiplying
                if (prod > MAX_VAL / nums[j]) break;

                prod *= nums[j];
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);

                if (prod == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
