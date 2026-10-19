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

        int ans1 = 0;
        int prev1 = 0;

        for (int i = 0; i < n - 1; i++) {
            int next1 = max(nums[i] + prev1 ,ans1);
            prev1 = ans1;
            ans1 = next1;
        }

        int ans2 = 0;
        int prev2 = 0;

        for (int i = n - 1; i >= 1; i--) {
            int next2 = max(nums[i] + prev2 , ans2);
            prev2 = ans2;
            ans2 = next2;
        }


        return max(ans1,ans2);
    }
};