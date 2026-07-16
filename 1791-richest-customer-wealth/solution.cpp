#include <numeric>

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = -1;
        for(auto x : accounts){
            int y = accumulate(x.begin(), x.end(), 0);
            if(y > ans){
                ans = y;
            }
        }
        
        return ans;
    }
};
