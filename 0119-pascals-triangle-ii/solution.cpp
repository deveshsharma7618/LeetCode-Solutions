class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
            return {1};
        } else if (rowIndex == 1) {
            return {1, 1};
        }
        vector<int> prev;
        vector<int> ans;
        prev.push_back(1);
        prev.push_back(1);
        for (int rowIdx = 2; rowIdx <= rowIndex; rowIdx++) {
            ans.push_back(1);
            ans.push_back(1);
            for (int i = 1; i < rowIdx; i++) {
                int x = prev[i - 1] + prev[i];
                ans.insert(ans.begin() + i, x);
            }
            prev = ans;
            if(rowIdx != rowIndex){
                ans.clear();
            }
        }

        return ans;
    }
};
