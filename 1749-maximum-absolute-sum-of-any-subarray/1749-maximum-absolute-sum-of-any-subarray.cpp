class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int min_sum = 0;
        int max_sum = 0;
        int prefix_sum = 0;

        for(int num :  nums){
            prefix_sum += num;
            max_sum = max(max_sum, prefix_sum);
            min_sum = min(min_sum, prefix_sum);
        }
        return max_sum - min_sum;
    }
};