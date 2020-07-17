/*************************************************************************
	> File Name: ZJ59-II_队列的最大值.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Jul 2020 11:58:44 AM CST
 ************************************************************************/

class MaxQueue {
public:
    MaxQueue() {
        while (!maxq.empty()) maxq.pop_front();
        while (!q.empty()) q.pop();
    }
    
    int max_value() {
        if (q.empty()) return -1;
        return maxq.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while (!maxq.empty() && value > maxq.back()) maxq.pop_back();
        maxq.push_back(value);
    }
    
    int pop_front() {
        if (q.empty()) return -1;
        int value = q.front();
        if (!maxq.empty() && value == maxq.front()) maxq.pop_front();
        q.pop();
        return value;
    }
private:
    deque<int> maxq;
    queue<int> q;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
