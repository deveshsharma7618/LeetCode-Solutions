class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,two=nums.size()-1;
        int mid = 0;
        int n = nums.size();
        while(mid <= two){
            if(nums[mid] == 0){
               swap(nums[zero],nums[mid]);
                mid++;
                zero++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid],nums[two]);
            two--;
            }
        }
    }
};
