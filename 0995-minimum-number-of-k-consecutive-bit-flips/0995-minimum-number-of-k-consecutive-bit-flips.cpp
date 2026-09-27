class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q;
        int flips = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if( !q.empty() && q.front() < i){
                q.pop();
            }

            if( q.size() % 2 == nums[i]){
                if( i >= n - k + 1 ){
                    return -1;
                }
                q.push( i + k - 1);
                flips++;
            }
        }
        return flips;
    }
};