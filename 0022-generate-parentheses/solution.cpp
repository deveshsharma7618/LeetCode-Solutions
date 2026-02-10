class Solution {
public:
    void solve(vector<string>& ans, int left, int right, string s, int n){
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }
        if(left< n){
            solve(ans,left+1,right, s+"(",n);
        }

        if(right < left){
            solve(ans,left,right+1,s+")",n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans,0,0,"",n);
        return ans;
    }
};
