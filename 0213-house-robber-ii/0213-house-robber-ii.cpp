class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        if( n == 2){
            return max(nums[0], nums[1]);
        }

        vector<int> ans(n);
        vector<int> temp(n);

        ans[0] = nums[0];
        ans[1] = max(nums[1], nums[0]);

        temp[n-1] = nums[ n - 1];
        temp[n-2] = max(nums[n-1], nums[n-2]);

        for (int i = 2; i < n - 1; i++) {
            ans[i] = max(nums[i] + ans[i - 2], ans[i - 1]);
        }

        for (int i = n - 3; i >= 1; i--) {
            temp[i] = max(nums[i] + temp[i + 2], temp[i + 1 ]);
        }


        return max(ans[n - 2], temp[1]);
    }
};