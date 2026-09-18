class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        result[0] = 1;
        result[1] = nums[0];
        for (int i = 2; i < nums.size(); i++) {
            result[i] = result[i-1]*nums[i-1];
        }
        int right_prod = nums[nums.size()-1];
        for (int j = nums.size()-2; j >=0; j--) {
            result[j] = result[j]*right_prod;
            right_prod*= nums[j];
        }
        return result;

    }
};
