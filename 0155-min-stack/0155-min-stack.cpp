class MinStack {
public:
    stack<int> st;
    stack<pair<int, int>> getMi;

    MinStack() {}

    void push(int val) {
        int minn;

        if (getMi.empty())
            minn = val;
        else
            minn = min(val, getMi.top().second);
        st.push(val);
        getMi.push({val, minn});
    }

    void pop() {
        st.pop();
        getMi.pop();
    }

    int top() { return st.top(); }

    int getMin() { return getMi.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */