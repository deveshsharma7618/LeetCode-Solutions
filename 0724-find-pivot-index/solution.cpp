class Solution {
public:
        vector<int> prefixSum(vector<int>& nums) {
            if(nums.empty()){
                return {};
            }
            vector<int> ans;
            ans.push_back(nums[0]);
            for(int i = 1; i < nums.size(); i++){
            
                ans.push_back(ans[i-1]+ nums[i]);
            }
            return ans;
    }
    
    int sumRange(vector<int>& x,int r, int l){
        if(l < 0 || r < 0){
            return 0;
        }
        
        if(r >= x.size() || l >= x.size()){
            return 0;
        }
        
        if( l == 0){
            return x[r];
        }
        
        return x[r]-x[l-1];
    }
    
    int pivotIndex(vector<int>& nums) {
        vector<int> temp = prefixSum(nums);
        for(int i=0;i<nums.size();i++){
            int l = sumRange(temp,i-1,0);
            int r = sumRange(temp, nums.size()-1, i+1);
            
            cout << l << " " << r << endl;
            if(l == r){
                return i;
            }
        
        }
        
        return -1;
    }
};
