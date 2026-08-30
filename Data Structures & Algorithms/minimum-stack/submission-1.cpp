class MinStack {
public:
    stack<int> st;
    stack<int> min_stack;
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        if(min_stack.empty()) min_stack.push(val);
        else if(min_stack.top() >= val) min_stack.push(val);
    }   
    
    void pop() {
        if(st.empty()) return;
        int t = st.top();
        st.pop();
        if(t == min_stack.top()) min_stack.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(min_stack.empty()) return -1;
        return min_stack.top();
    }
};
