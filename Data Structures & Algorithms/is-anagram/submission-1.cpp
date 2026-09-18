class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> cache;
        for (int i = 0; i < 26; i++) {
            cache[i] =0;
        }
        for (char c: s) {
            cache[c - 'a']++;
        }
        for (char b: t) {
            if (cache[b - 'a'] == 0) {
                return false;
            } else {
                cache[b - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (cache[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
