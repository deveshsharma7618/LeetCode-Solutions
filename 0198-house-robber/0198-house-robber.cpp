class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if( n == 0){
            return 0;
        }

        if( n == 1){
            return nums[0];
        }

        vector<int> ans( nums.size());
        ans[0] = nums[0];
        ans[1] = max(nums[1], nums[0]);

        for (int i = 2 ; i < nums.size(); i++) {
            ans[i] = max( nums[i] + ans[ i -2 ], ans[i - 1]);
        }

        return ans[nums.size() - 1];
    }
};