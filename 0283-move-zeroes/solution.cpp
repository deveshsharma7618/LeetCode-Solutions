class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;
        int read = 0;
        int n = nums.size();
        while(read < n){
            
            if(nums[read] != 0){
                nums[write] = nums[read];
                write++;
            }
            read++;
        }
        
        while(write < n){
            nums[write++] = 0;
        }
    }
};
