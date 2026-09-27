class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        vector<int> dravolenti = nums;

        int n = dravolenti.size();
        vector<int> freq(501, 0);

        int l = 0;
        int ans = 0;

        auto validAfterAdding = [&](int x) -> bool {

            // Case 1:
            // a + b = x
            //
            // a and b must both come from the OLD window.
            for (int a = 1; a < x; a++) {
                int b = x - a;

                if (a == b) {
                    if (freq[a] >= 2)
                        return false;
                }
                else {
                    if (freq[a] > 0 && freq[b] > 0)
                        return false;
                }
            }

            // Case 2:
            // x + a = b
            //
            // a and b must come from the OLD window.
            //
            // IMPORTANT:
            // freq[x] currently includes the newly added x.
            // Therefore a == x must require freq[x] >= 2.
            for (int a = 1; a + x <= 500; a++) {

                if (a == x) {
                    if (freq[x] >= 2 && freq[2 * x] > 0)
                        return false;
                }
                else {
                    if (freq[a] > 0 && freq[a + x] > 0)
                        return false;
                }
            }

            return true;
        };

        for (int r = 0; r < n; r++) {
            int x = dravolenti[r];

            freq[x]++;

            while (!validAfterAdding(x)) {
                freq[dravolenti[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
