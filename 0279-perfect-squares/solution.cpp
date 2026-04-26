class Solution {
public:
    
    int solve(int n, vector<int>& squares, vector<int>& dp) {
        
        if(n == 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int ans = INT_MAX;
        
        for(int sq : squares) {
            
            if(sq > n)
                break;
            
            ans = min(ans, 1 + solve(n - sq, squares, dp));
        }
        
        return dp[n] = ans;
    }
    
    int numSquares(int n) {
        
        vector<int> squares;
        
        for(int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }
        
        vector<int> dp(n + 1, -1);
        
        return solve(n, squares, dp);
    }
};
