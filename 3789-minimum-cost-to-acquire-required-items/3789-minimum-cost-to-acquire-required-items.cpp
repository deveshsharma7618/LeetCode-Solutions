class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long minCost = min({cost1 + cost2, costBoth});
        long long minNeed = min({need1, need2});

        long long cost = 0;

        cost += minNeed * minCost;
        need1 -= minNeed;
        need2 -= minNeed;

        if (need1 > 0) {
            minCost = min({cost1, costBoth});
            cost += need1 * minCost;
        } else {
            minCost = min({cost2, costBoth});
            cost += need2 * minCost;
        }

        return cost;
    }
};