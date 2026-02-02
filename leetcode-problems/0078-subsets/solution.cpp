class Solution {
    void subsetsHelper(vector<int>& nums,int i, vector<int> temp, vector<vector<int>> &ans){
        if(i >= nums.size()){
            ans.push_back(temp);
            return;
        }

        subsetsHelper(nums,i+1, temp, ans);

        temp.push_back(nums[i]);
        subsetsHelper(nums,i+1, temp,ans);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        subsetsHelper(nums, 0, temp, ans);
        return ans;
    }
};
