class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size()-1;
        int l = 0;
        int r = size;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                return {(l+1),(r+1)};
            }
            if (sum > target) {
                r--;
            } else {
                l++;
            }
        }
        return {};
        
    }
};
