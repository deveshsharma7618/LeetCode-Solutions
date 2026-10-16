class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        
        for (int i = 0; i < n; i++) {
            v[i] = {nums[i], i};
        }
        
        // Find top k elements in O(N) average time
        nth_element(v.begin(), v.begin() + k, v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        // Sort only the first k elements by original index
        sort(v.begin(), v.begin() + k, [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        
        // Extract values into final answer
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }
        
        return ans;
    }
};