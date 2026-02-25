class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& temp, int k, int n,
               int j) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        if(j > n){
            return;
        }
        temp.push_back(j);
        solve(ans, temp, k, n, j + 1);
        temp.pop_back();
        solve(ans, temp, k, n, j + 1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, k, n, 1);
        return ans;
    }
};
