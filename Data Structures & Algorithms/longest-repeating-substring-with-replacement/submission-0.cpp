class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> hash;
        int result = 0;
        int max_freq = 0;
        int l = 0;
        for (int i = 0; i < s.length(); i++) {
            hash[s[i]]++;
            // the line below works because only s[i]'s count changes so only it needs to be checked
            max_freq = max(max_freq, hash[s[i]]);

            while ((i-l+1 - max_freq) > k) {
                hash[s[l]]--;
                l++;
            }

            result = max(i-l+1, result);
        }
        return result;
    }
};
