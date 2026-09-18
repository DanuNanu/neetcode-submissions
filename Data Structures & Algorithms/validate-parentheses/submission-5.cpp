class Solution {
public:
    bool isValid(string s) {
        stack<char> doop;
        if (s.length() % 2 != 0) {
            return false;
        }
        for (char c: s) {
            if ((c == '}'|| c == ']' || c == ')') && doop.empty()) {
                return false;
            }
            switch (c) {
                case '}':
                    if (doop.top() != '{')
                        return false;
                    doop.pop();
                    break;
                case ']':
                    if (doop.top() != '[')
                        return false;
                    doop.pop();
                    break;
                case ')':
                    if (doop.top() != '(')
                        return false;
                    doop.pop();
                    break;
                default:
                    doop.push(c);

            }
        }
        return doop.empty();
        
    }
};
