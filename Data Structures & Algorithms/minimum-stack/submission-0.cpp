class MinStack {
    stack<int> mainStack;
    stack<int> minStack;

public:
    MinStack() {
        // Constructor initializes the stacks
    }
    
    void push(int val) {
        mainStack.push(val);
        
        // If minStack is empty, the current value is the minimum.
        // Otherwise, push the minimum between the current value and the current minimum.
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            minStack.push(std::min(val, minStack.top()));
        }
    }
    
    void pop() {
        if (!mainStack.empty()) {
            mainStack.pop();
            minStack.pop();
        }
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};