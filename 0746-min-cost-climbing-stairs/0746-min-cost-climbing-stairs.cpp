class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if( n == 3){
            return min(cost[1], min( cost[0] + cost[2], cost[2] + cost[1]));
        }

        int prev1 = cost[n - 1];
        int prev2 = cost[n - 2];

        int ans1 = min(prev1, prev2);

        for (int i = n - 3; i >= 0; i--) {
            ans1 = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = ans1;
        }

        prev1 = cost[n - 1];
        prev2 = cost[n - 2];
        int ans2 = min(prev1, prev2);

        for (int i = n - 3; i >= 1; i--) {
            ans2 = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = ans2;
        }
        return min(ans1, ans2);
    }
};