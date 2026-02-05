class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int currEnd = 0;
        int farthest = 0;
        
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == currEnd) {
                currEnd = farthest;
            }
        }
        if(currEnd < n-1){
            return false;
        }else{
            return true;
        }
    }
};
