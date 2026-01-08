class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int x = nums[0];
        int freq = 1;
        for(int i=1;i<n; i++){
            if(nums[i] != x){
                if(freq > n/3){
                    ans.push_back(x);
                }
                freq = 1;
                x = nums[i];
            }else{
                freq++;
            }
        }
        
        if(freq > n/3){
            ans.push_back(x);
        }
        return ans;
    }
};
