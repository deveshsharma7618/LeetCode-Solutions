class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        int n = nums.size();

        // Group indices by value
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        vector<long long> ans(n);

        // Process each group
        for (auto& [val, v] : pos) {
            int m = v.size();
            vector<long long> prefix(m + 1, 0);

            for (int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + v[i];
            }

            for (int i = 0; i < m; i++) {
                long long left = (long long)v[i] * i - prefix[i];
                long long right =
                    (prefix[m] - prefix[i + 1]) - (long long)v[i] * (m - i - 1);
                ans[v[i]] = left + right;
            }
        }

        return ans;
    }
};
