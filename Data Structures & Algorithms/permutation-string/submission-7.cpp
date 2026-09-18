class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //first we do a few fail fast conditions
        //if s2 is shorter than s1 then obviously its false
        int length1 = s1.length();
        int length2 = s2.length();
        if (length1 > length2) {
            return false;
        }
        // if same length then they must have same freq of characters
        int cache1[26] ={0};
        int cache2[26] = {0};
        int left_index =0;
        for (char c: s1) {
            cache1[c-'a']++;
        }
        bool ans = false;
        int k = 0;
        for (int i = length1-1; i < length2; i++) {
            if (i == length1-1) {
                while (k < length1) {
                    cache2[s2[k]-'a']++;
                    k++;
                }
            } else {
                cache2[s2[i]-'a']++;
                cache2[s2[left_index]-'a']--;
                left_index++;
            }
            // common ground
            if(std::equal(std::begin(cache1), std::end(cache1), std::begin(cache2)))
                return true;
            
        }
        return false;
         
    }
};
