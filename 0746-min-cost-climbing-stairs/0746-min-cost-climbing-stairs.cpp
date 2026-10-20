class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int prev2 = cost[n - 1];
        int prev1 = cost[n - 2];
        
        for (int i = n - 3; i >= 0; i--) {
            int current = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = current;
        }
        
        return min(prev1, prev2);
    }
};