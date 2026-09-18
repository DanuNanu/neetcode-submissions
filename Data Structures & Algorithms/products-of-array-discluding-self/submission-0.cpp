class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //with division operator
        //plan multiply every nonzero term and store the terms that are 0
        //if more than one has 0 then every result is 0;
        int product = 1;
        vector<int> zeroList;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroList.push_back(i);
                if (zeroList.size()> 1) {
                    vector<int> result(nums.size(), 0);
                    return result;
                }
                continue;
            }
            product *= nums[i];
        }
        if (!zeroList.empty()) {
           vector<int> result(nums.size(), 0);
           result[zeroList[0]] = product;
           return result;
        }
        vector<int> result(nums.size(),product);
        for (int i = 0; i < nums.size(); i++) {
            result[i] = result[i]/nums[i];
        }
        return result;
    }
};
