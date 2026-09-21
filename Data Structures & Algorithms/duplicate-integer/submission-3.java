class Solution {
    public boolean hasDuplicate(int[] nums) {
        Set<Integer> cache = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (cache.contains(nums[i])) {
                return true;
            } else {
                cache.add(nums[i]);
            }
        }
        return false;
        
    }
}