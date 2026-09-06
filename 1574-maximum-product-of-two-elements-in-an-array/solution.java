class Solution {
    public int maxProduct(int[] nums) {
        
        int highHigh = nums[0] > nums[1] ? 0 : 1;
        int highLow  = nums[0] < nums[1] ? 0 : 1;

        for(int i = 2 ; i < nums.length; i++){

            if(nums[i] > nums[highHigh]){
                highLow = highHigh;
                highHigh = i;
            }else if( nums[i] > nums[highLow]){
                highLow = i;
            }
        }

        return ( nums[highHigh] -1 ) * ( nums[highLow] - 1);


    }
}
