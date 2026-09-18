class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> cache;
        int look = 0;
        for (int i = 0; i < nums.size(); i++) {
            look = target-nums[i];
            if (cache.count(look)) {
                return {cache[look],i};
            } else {
                cache.insert({nums[i],i});
            }
        }
        return {0,1};
        
    }
};
