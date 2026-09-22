class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] result = new int[nums.length];
        result[0] = 1;
        for (int i = 1; i < nums.length; i++) {
            if (i == 1) {
                result[i] = nums[0]; 
                continue;
            } 
            result[i] = result[i-1]*nums[i-1];
        }
        int right_multip = 1;
        for (int i = nums.length-1; i >= 0; i--) {
            result[i] = result[i] * right_multip;
            right_multip =  right_multip* nums[i];
        }
        return result;
    }
}  
