class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {}

    void push(int x) { q1.push(x); }

    int pop() {
        int x;
        while (!q1.empty()) {
            x = q1.front();
            q1.pop();
            if (!q1.empty()) {
                q2.push(x);
            }
        }
        while (!q2.empty()) {
            int y = q2.front();
            q1.push(y);
            q2.pop();
        }
        return x;
    }

    int top() {
        int x;
        while (!q1.empty()) {
            x = q1.front();
            q1.pop();
            q2.push(x);
        }
        while (!q2.empty()) {
            int y = q2.front();
            q1.push(y);
            q2.pop();
        }
        return x;
    }

    bool empty() {
        if (q1.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
