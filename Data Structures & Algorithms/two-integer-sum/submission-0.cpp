class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> cache;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            int sub = target-nums[i];
            if (cache.count(sub)) {
                return {cache[sub], i};
            }
            if (!cache.count(nums[i])) {
                cache.insert({nums[i], i});
            }
        }

    }
};
