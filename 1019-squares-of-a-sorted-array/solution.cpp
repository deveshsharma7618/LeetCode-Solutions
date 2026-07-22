class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        
        vector<int> ans;
        int k = 0;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(abs(nums[i]) < abs(nums[k])){
                k = i;
            }
        }
        
        ans.push_back(nums[k]*nums[k]);
        int i = k-1, j = k+1;
        
        while(i >= 0 && j < n){
            if(abs(nums[i]) > abs(nums[j])){
                ans.push_back(nums[j]*nums[j]);
                j++;
            }else{
                ans.push_back(nums[i] * nums[i]);
                i--;
            }
        }
        
        while(i >= 0){
            ans.push_back(nums[i]*nums[i]);
            i--;
        }
        
        while(j < n){
            ans.push_back(nums[j]*nums[j]);
            j++;
        }
        
        
        return ans;
    }
};
