class Solution {
public:
    bool isValid(string s) {
        int size = s.length();
        vector<char> cache;

        for (int i = 0; i < size; i++) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                cache.push_back(s[i]);
                continue;
            } else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
                char check;
                if (!cache.empty()) {
                    check = cache.back();
                } else {
                    return false;
                }
                switch  (s[i]) {
                    case '}':
                        if (check != '{') return false;
                        cache.pop_back();
                        break;
                    case ']':
                        if (check != '[') return false;
                        cache.pop_back();
                        break;
                    case ')':
                        if (check != '(') return false;
                        cache.pop_back();
                        break;
                    default:
                        return false;
                }
                continue;
            } else {
                return false;
            }
        }
        return cache.empty(); 
    }
};
