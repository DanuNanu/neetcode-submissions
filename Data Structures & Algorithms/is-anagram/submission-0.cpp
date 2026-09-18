class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> log;
        unordered_map<char, int> log2;
        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            log[s[i]]++;
            log2[t[i]]++;
        }
        return log == log2;
    }
};
