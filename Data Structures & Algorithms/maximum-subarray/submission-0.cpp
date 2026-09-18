class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int high_score = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (max_so_far + nums[i] < nums[i]) {
                max_so_far = nums[i];
            } else {
                max_so_far += nums[i];
            }
            if (max_so_far >= high_score) {
                high_score = max_so_far;
            }
        }
        return high_score;

    }
};
