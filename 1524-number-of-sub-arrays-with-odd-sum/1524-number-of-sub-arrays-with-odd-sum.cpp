class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long ans = 0;
        int n = arr.size();

        int prevOdd = 0;
        int prevEven = 0;

        vector<long long> cf(n, 0);

        cf[0] = arr[0];

        for (int i = 1; i < n; i++) {
            cf[i] = arr[i] + cf[i - 1];
        }

        for (int i = 0; i < n; i++) {
            if (cf[i] % 2 == 1) {
                ans += 1 + prevEven;
                prevOdd++;
            } else {
                ans += prevOdd;
                prevEven++;
            }

            ans %= 1000000007LL;
        }

        return ans;
    }
};