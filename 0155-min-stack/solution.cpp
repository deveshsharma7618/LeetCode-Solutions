class MinStack {
public:
    stack<int> s;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        int min = INT_MAX;
        stack<int> t;
        while(!s.empty()){
            int x = s.top();
            s.pop();
            t.push(x);
            if(x < min){
                min = x;
            }
        }

        while(!t.empty()){
            int x = t.top();
            t.pop();
            s.push(x);
        }

        return min;
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
