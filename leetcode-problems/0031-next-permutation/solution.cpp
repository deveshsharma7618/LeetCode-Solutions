class Solution {
public:
    void backvers(vector<int> &nums, int start, int end){
        while (start < end){
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int idx = -1, length = nums.size();
        for (int i = length-2 ; i >= 0 ; i--){
            if (nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

        if (idx==-1){
            backvers(nums, 0, length-1);
            return;
        }

        backvers(nums, idx+1, length-1);
        int newj = -1;
        for(int j = idx+1; j < length; j++){
            if (nums[idx]<nums[j]) {
                newj = j;
                break;
            }
        }

        swap(nums[idx], nums[newj]);

    }
};
