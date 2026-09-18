class Solution {
public:
    bool isAnagram(string s, string t) {
        int cache[26] = {0};
        if (s.length() != t.length()) {
            return false;
        }
        for (char c: s) {
            cache[c - 'a']++;
        }
        for (char b: t) {
            cache[b- 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (cache[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
