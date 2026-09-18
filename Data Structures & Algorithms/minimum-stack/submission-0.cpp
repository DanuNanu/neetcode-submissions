class MinStack {
public:
    stack<int> min;
    stack<int> regular_min;
    MinStack() {
        
    }
    
    void push(int val) {
        min.push(val);
            // so then this would guarentee ther redundancy needed
            val = std::min(val, regular_min.empty()? val: regular_min.top());
            regular_min.push(val);
        }
    
    
    void pop() {
        min.pop();
        regular_min.pop();
    }
    
    int top() {
        return min.top();
    }
    
    int getMin() {
        return regular_min.top();
    }
};
