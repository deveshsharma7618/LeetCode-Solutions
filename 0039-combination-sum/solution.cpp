class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& ans,
                vector<int>& temp, int s, int i) {
        if (s > target) return; 
        if (s == target) {
            ans.push_back(temp);
            return;
        }
        for (int j = i; j < candidates.size(); j++) {
            temp.push_back(candidates[j]);
            helper(candidates, target, ans, temp, s + candidates[j], j); 
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(candidates, target, ans, temp, 0, 0);
        return ans;
    }
};
