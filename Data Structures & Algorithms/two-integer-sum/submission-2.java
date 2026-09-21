class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> cache = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int sub = target - nums[i];
            if (cache.containsKey(sub)) {
                return new int[]{cache.get(sub), i};
            } else {
                cache.put(nums[i], i);
            }
        }
        return new int[]{};
    }
}
