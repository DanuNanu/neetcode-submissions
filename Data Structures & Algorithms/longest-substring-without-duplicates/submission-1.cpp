class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int left = 0;
        int current_length = 0;
        unordered_set<char> window;
        for (int i = 0; i < s.length(); i++) {
            while (window.find(s[i]) != window.end()) {
                window.erase(s[left]);
                left++;
            }
            window.insert(s[i]);
            max_length = max(i - left +1, max_length);
            
        }
        return max_length;
        
    }
};
