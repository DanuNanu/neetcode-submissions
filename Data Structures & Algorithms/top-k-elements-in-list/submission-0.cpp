class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //plan 1: go through array and tally up frequency in a map
        //sort the map then return result but thats stupid
        //want O(n) so definitely need to do tally
        //issue is with duplicate tallies existing then how
        //can update map until the entire vector is run through
        //since tallies are dyanamic

        //plan currently definitely to first make a map of tallies
        //need algo to group numbers together
        //what if make another map and go through every key and make the value
        //in the original map, the key in the new map and update it as it goes alogn

        unordered_map<int, int> cache;
        int max = 1;
        int size = nums.size();
        for (int num: nums) {
            if (!cache.count(num)) {
                cache[num] =1;
            } else {
                cache.at(num) +=1;
                // variable = (condition) ? expressionTrue : expressionFalse;
                max = (cache.at(num) > max) ? cache.at(num) : max;
            }
        }
        unordered_map<int, vector<int>> result;
        for (const auto& pair: cache) {
            result[(pair.second)].push_back(pair.first);
        }

        int temp = k;
        vector<vector<int>> concat;
        vector<int> answer;
        for (int i = max; i > 0; i--) {
            if (result[i].empty()) {
                continue;
            } 
            concat.push_back(result[i]);
        }

        for (int j = 0; j < concat.size(); j++) {
            if (temp == 0) {
                return answer;
            }
           for (int unit: concat[j]) {
                answer.push_back(unit);
                temp--;
                if (temp == 0) {
                    return answer;
                }
           }
    }
    return{};
    }
};
