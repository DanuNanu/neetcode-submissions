class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        int current_sum = 0;
        dfs(nums, 0, 0, subset, res,target);
        return res;
    }

    private:
        void dfs(vector<int>& nums, int i, int current_sum, vector<int>& subset, vector<vector<int>>& res, int target) {
            //base case: if equals target, if sum is greater than target
            // dfs at each point can exclude or include
            if (current_sum == target) {
                res.push_back(subset);
                return;
            } else if (current_sum > target|| i >= nums.size()) {
                return;
            }
            subset.push_back(nums[i]);
            dfs(nums, i, current_sum+nums[i], subset, res, target);
            subset.pop_back();
            dfs(nums, i+1, current_sum, subset, res, target);
        }


};
