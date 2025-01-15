class MinStack {
public:
    stack<int>s;
    stack<int>s1;
    MinStack() {
        
    }
    
    void push(int val) {
       s.push(val); 
       s1.push(min(val, s1.empty() ? val : s1.top()));
    }
    
    void pop() {
        s.pop();
        s1.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s1.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */