class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(i < n && j < n){
            while(nums[i] < 0)
                i++;
            while(nums[j] > 0)
                j++;
            ans.push_back(nums[i++]);
            ans.push_back(nums[j++]);
        }
        return ans;
    }
};
