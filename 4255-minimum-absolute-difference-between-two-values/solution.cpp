class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int minDiff = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if( (nums[i] == 1 && nums[j] == 2 ) || (nums[i] == 2 && nums[j] == 1)) {
                    minDiff = min(minDiff, abs(j-i));
                }
            }
        }
        if(minDiff == INT_MAX){
            return -1;
        }
        return minDiff;
    }
};
