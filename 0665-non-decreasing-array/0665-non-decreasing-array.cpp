class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        if (n <= 2)
            return true;

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > nums[i + 1] && nums[i + 1] <= nums[i + 2]) {

                if (nums[i] >= nums[i + 2]) {
                    nums[i] = nums[i + 1];
                } else {
                    nums[i + 1] = nums[i];
                }

                cnt++;

            } else if (nums[i] > nums[i + 1] && nums[i + 1] > nums[i + 2]) {

                return false;

            } else if (nums[i] <= nums[i + 1] && nums[i + 2] < nums[i + 1]) {


                if (nums[i + 2] >= nums[i]) {
                    nums[i + 1] = nums[i];
                } else {
                    nums[i + 2] = nums[i + 1];
                }

                cnt++;
                
            }
        }

        return cnt <= 1;
    }
};