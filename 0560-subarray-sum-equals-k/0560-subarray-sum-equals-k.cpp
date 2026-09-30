class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // code here
        int ans = 0;

        unordered_map<int, int> mp;
        

        int n = nums.size();

        vector<int> prefix(n, 0);
        for (int i = 0; i < n; i++) {
            prefix[i] += nums[i] + (i >= 1 ? prefix[i - 1] : 0);

            if (prefix[i] == k) {
                ans++;
            }

            if (mp.find(prefix[i] - k) != mp.end()) {
                ans += mp[prefix[i] - k];
            }

            if (mp.count(prefix[i])) {
                mp[prefix[i]] += 1;
            } else {
                mp[prefix[i]] = 1;
            }
        }

        return ans;
    }
};