class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        vector<int> cache1(26);
        vector<int> cache2(26);
        bool result = true;
        int left = 0;

        if (s2.length() < s1.length()) {
            return false;
        }

        for (int i = 0; i < k; i++) {
            cache1[s1[i]-'a']++;
            cache2[s2[i]-'a']++;
        }

        if (s1.length() == s2.length()) {           
            for (int j = 0; j < 26; j++) {
                if (cache1[j] != cache2[j]) {
                    return false;
                }
            }
            return true;
        }

        for (int j = 0; j < 26; j++) {
            if (cache1[j] != cache2[j]) {
                result = false;
                break;
            }
        }

        if (result) {
            return result;
        }

         for (int i = k; i < s2.length(); i++) {
            cache2[s2[i]-'a']++;
            cache2[s2[left]-'a']--;
            left++;
            
            bool ans = true;
            for (int j = 0; j < 26; j++) {
                if (cache1[j] != cache2[j]) {
                    ans = false;
                    break;
                }
            }
            if (ans) {
                return ans;
            }
         }
         return false;
         
    }
};
