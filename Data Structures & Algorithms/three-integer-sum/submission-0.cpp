class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size()-1; i++) {
            if (i> 0 && nums[i] == nums[i-1])
                 continue;
            int target = -nums[i];
            int left = i+1;
            int right = size-1;
            while (left < right) {
                int sum = nums[right] + nums[left];
                if (sum == target) {
                    result.push_back({-target, nums[right], nums[left]});
                    right--;
                    left++;
                    while (left < right && nums[left] == nums[left-1])  
                        left++;
                    while(left< right && nums[right] == nums[right+1])
                        right--;
                } else if (sum > target) {
                    right--;
                } else {
                    left++;
                }
            }

        }
        return result;
    }
};
