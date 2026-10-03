class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1;
        int ans = 0;
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            product *= nums[i];
            
            while (start <= i && product > 1 && product >= k) {
                product /= nums[start];
                start++;
            }

            if (product < k) {
                ans += (i - start + 1);
            }

            if (product <= 0) {
                product = 1;
            }
        }

        return ans;
    }
};