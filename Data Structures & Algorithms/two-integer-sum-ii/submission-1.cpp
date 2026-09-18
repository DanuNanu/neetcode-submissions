class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int right = numbers.size()-1;
        int left = 0;
        int sum =0;
        while (left < right) {
            sum = numbers[left]+ numbers[right];
            if (target == sum) {
                return {left+1, right+1};
            } else if (target < sum) {
                right--;
            } else {
                left++;
            }
        }
        return {};
    }
};
