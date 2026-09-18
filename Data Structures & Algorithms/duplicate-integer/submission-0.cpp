class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> bet;
        for (int num: nums) {
            if (bet.find(num) != bet.end()) {
                return true;
            } else {
                bet.insert(num);
            }
        }
        return false;
    }
};