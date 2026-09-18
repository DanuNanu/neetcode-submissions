class Solution {
public:
    bool isPalindrome(string s) {
        int right= s.length()-1;
        int left  = 0;
        while (left < right) {
            if (!isalnum(s[left]) || !isalnum(s[right])){
                if (!isalnum(s[left]))
                    left++;
                if (!isalnum(s[right]))
                    right--;
                continue;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            right--;
            left++;
        }
        return true;
    }
};
