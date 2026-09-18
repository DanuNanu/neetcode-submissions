class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        vector<int> cache1(26);
        vector<int> cache2(26);
        unordered_set<char> tally;
        bool result = true;
        int left = 0;

        if (s2.length() < s1.length()) {
            return false;
        }

        for (int i = 0; i < k; i++) {
            tally.insert(s1[i]-'a');
            cache1[s1[i]-'a']++;
            cache2[s2[i]-'a']++;
        }

        if (s1.length() == s2.length()) {           
            for (const auto& element: tally) {
                if (cache1[element] != cache2[element]) {
                    return false;
                }
            }
            return true;
        }

        for (const auto& element: tally) {
            if (cache1[element] != cache2[element]) {
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
            for (const auto& element: tally) {
                if (cache1[element] != cache2[element]) {
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
