// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.


class MinStack {
public:
    MinStack() {
        
    }
    vector<int> st;
    
    void push(int val) {
        
        st.push_back(val);
        
    }
    
    void pop() {
        if(st.size()>=1)
            st.pop_back();
        
    }
    
    int top() {
        return (st[st.size()-1]);
    }
    
    int getMin() {
        
        int a=*min_element(st.begin(),st.end());
        return a;
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