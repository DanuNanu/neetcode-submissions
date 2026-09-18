class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int num: nums) {
            hash[num]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for (auto& [key,value]: hash) {
            buckets[value].push_back(key);
        }

        vector<int> results;
        for (int i = buckets.size()-1; i>=0 && results.size() <k; i--) {
            for (int num: buckets[i]) {
                results.push_back(num);
            }
        }
        return results;
    }
};
