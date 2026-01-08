bool basedOnStart(vector<int> interval1, vector<int> interval2){
    return interval1[0] < interval2[0];
}

class Solution {
public:
    
   vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end(), basedOnStart);

        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            } else {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});
        return ans;
    }
};
