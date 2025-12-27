class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int maxfreq = 1;
        long long sum = 0;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            if(sum + k < (long long)nums[right] * (right - left + 1)){
                sum -= nums[left];
                left++;
            }

            maxfreq = max(maxfreq, right-left + 1);
        }
        return maxfreq;
    }
};
