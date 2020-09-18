/*************************************************************************
	> File Name: 155_最小栈.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Sep 2020 06:08:25 PM CST
 ************************************************************************/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        while (!mins.empty()) mins.pop();
        while (!s.empty()) s.pop();
    }
    
    void push(int x) {
        s.push(x);
        if (mins.empty() || x <= mins.top()) mins.push(x);
    }
    
    void pop() {
        if (s.top() == mins.top()) mins.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
private:
    stack<int> mins;
    stack<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
