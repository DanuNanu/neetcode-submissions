class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cache; 
        int left_index = 0;
        int size = s.length();
        int max_length = 0;

        for (int i = 0; i < size; i++) {
            while (cache.find(s[i]) != cache.end()) {
                cache.erase(s[left_index]);
                left_index++;
            }
            cache.insert(s[i]);
            max_length = max(i - left_index + 1, max_length);
        }
        return max_length;
    }
};
