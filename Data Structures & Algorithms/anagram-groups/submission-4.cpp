class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>cache;
        for (string& s: strs) {
            cache[keyconvert(s)].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& [keyed,value]: cache) {
            result.push_back(move(value));
        }
        return result;
    }


    string keyconvert(string& s) {
        int count[26] = {0};
        for (char c: s) {
            count[c-'a']++;
        }
        string key;
        for (int i = 0; i < 26; i++) {
            key += '#';
            key+= to_string(count[i]);
        }
        return key;
    }
};
