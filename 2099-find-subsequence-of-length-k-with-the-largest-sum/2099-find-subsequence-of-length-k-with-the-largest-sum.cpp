class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Step 1: Store elements with their original indices
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }
        
        // Step 2: Sort by value in descending order
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        // Step 3: Take top k elements
        vector<pair<int, int>> topK(v.begin(), v.begin() + k);
        
        // Step 4: Sort back by original index to maintain order
        sort(topK.begin(), topK.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        
        // Step 5: Extract values into final answer
        vector<int> ans;
        for (auto& p : topK) {
            ans.push_back(p.first);
        }
        
        return ans;
    }
};