class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return 0;
        }

        sort(intervals.begin(), intervals.end());

        int ans = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] < prevEnd) {
                // Overlap
                ans++;

                // Keep the interval that ends earlier
                prevEnd = min(prevEnd, intervals[i][1]);
            }
            else {
                // No overlap
                prevEnd = intervals[i][1];
            }
        }

        return ans;
    }
};
