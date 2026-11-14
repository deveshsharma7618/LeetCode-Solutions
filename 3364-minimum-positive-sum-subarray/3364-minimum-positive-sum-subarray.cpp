class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        
        int n = nums.size();
        vector<int> cf(n, 0);
        cf[0] = nums[0];

        for (int i= 1; i < nums.size(); i++) {
            cf[i] = cf[i-1] + nums[i];
        }

        int minSum = INT_MAX;

        for (int i = 0; i < n ; i++) {
            for (int j = i; j < n; j++) {
                int sumInterval = cf[j] - ( i > 0 ? cf[i - 1] : 0 );
                int x = j - i + 1;
                if (sumInterval > 0 && sumInterval < minSum &&  x >= l && x <= r) {
                    minSum = sumInterval;
                }
            }
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};