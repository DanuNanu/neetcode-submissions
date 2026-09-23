class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) {
            return intervals;
        }
        std::sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        int k = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result[k][1]) {
                result[k][1] = std::max(intervals[i][1], result[k][1]);
            } else {
                result.push_back(intervals[i]);
                k++;
            }
        }
        return result;
    }
};
