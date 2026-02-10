class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = nums.size()-1;
        for(int i=0;i<=j;i++){
            while(j >= i && nums[j] == val){
                j--;
            }
            
            if(j >= i && nums[i] == val){
                nums[i] = nums[j];
                j--;
            }
        }
        return j+1;
    }
};
