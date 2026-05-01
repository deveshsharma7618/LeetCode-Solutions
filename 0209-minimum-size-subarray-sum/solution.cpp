class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int startIdx = 0;
        int sum = 0;
        int len = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum >= target){
                
                while( sum >= target && startIdx <= i){
                    len = min(len,i - startIdx +1);
                    sum -= nums[startIdx];
                    startIdx++;
                }
            }
        }
        if(len == INT_MAX){
            return 0;
        }
        return len;
    }
};
