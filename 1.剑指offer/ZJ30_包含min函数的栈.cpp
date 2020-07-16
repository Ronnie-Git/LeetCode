class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        while (!sta.empty()) sta.pop();
        while (!minSta.empty()) minSta.pop();
    }
    
    void push(int x) {
        sta.push(x);
        if (minSta.empty() || x <= minSta.top()) minSta.push(x); 
    }
    
    void pop() {
        if (sta.empty()) return ;
        if (sta.top() == minSta.top()) minSta.pop();
        sta.pop();
        return ;
    }
    
    int top() {
        return sta.top();
    }
    
    int min() {
        return minSta.top();
    }
private:
    stack<int> sta;
    stack<int> minSta;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */