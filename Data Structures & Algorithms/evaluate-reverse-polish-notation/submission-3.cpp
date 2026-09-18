class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        unordered_map<string, std:: function<int(int,int)>> opt = {
            {"+", [](int a, int b) {return a +b;}},
            {"-", [](int a, int b) {return b-a;}},
            {"/", [](int a, int b) {return b/a;}},
            {"*", [](int a, int b) {return a*b;}},
        };
        for (string s: tokens) {
            if (opt.count(s)) {
                int a = operands.top();
                operands.pop();
                int b = operands.top();
                operands.pop();
                operands.push(opt[s](a,b));
            } else {
                operands.push(stoi(s));
            }
        }
        return operands.top();
        
    }
};
