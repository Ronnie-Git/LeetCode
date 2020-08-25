/*************************************************************************
	> File Name: 03.05_栈排序.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Aug 2020 12:15:52 AM CST
 ************************************************************************/

class SortedStack {
public:
    SortedStack() {
        while (!s.empty()) s.pop();
        while (!temp.empty()) temp.pop();
    }
    
    void push(int val) {
        if (s.empty() || val <= s.top()) s.push(val);
        else {
            while (!s.empty() && s.top() < val) {
                temp.push(s.top());
                s.pop();
            }
            s.push(val);
            while(!temp.empty()) {
                s.push(temp.top());
                temp.pop();
            }
        }
    }
    
    void pop() {
        if (!isEmpty()) s.pop();
    }
    
    int peek() {
        return isEmpty() ? -1 : s.top();
    }
    
    bool isEmpty() {
        return s.empty();
    }
private:
    stack<int> s;
    stack<int> temp;
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
