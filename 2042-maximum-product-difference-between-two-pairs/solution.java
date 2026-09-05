class Solution {
    public static int maxProductDifference(int[] nums) {
        // Intuition: Find 2 largest and 2 lowest
        int highLow = Math.min(nums[0], nums[1]);
        int highHigh = Math.max(nums[0], nums[1]);
        int lowHigh = Math.max(nums[0], nums[1]);
        int lowLow = Math.min(nums[0], nums[1]);

        for (int i = 2; i < nums.length; i++) {
            if (nums[i] < lowLow) {
                lowHigh = lowLow;
                lowLow = nums[i];
            } else if (nums[i] < lowHigh) {
                lowHigh = nums[i];
            }

            if (nums[i] > highHigh) {
                highLow = highHigh;
                highHigh = nums[i];
            } else if (nums[i] > highLow) {
                highLow = nums[i];
            }
        }

        return (highLow * highHigh) - (lowHigh * lowLow);
    }
}
