class CQueue {
public:
    CQueue() {
    	while (!sta1.empty()) sta1.pop();
    	while (!sta2.empty()) sta2.pop();
    }
    
    void appendTail(int value) {
    	sta1.push(value);
    }
    
    int deleteHead() {
    	if (sta2.empty()) {
    		while (!sta1.empty()) {
    			sta2.push(sta1.top());
    			sta1.pop();
    		}
    	}
    	if (sta2.empty()) return -1;
    	int ret = sta2.top();
    	sta2.pop();
    	return ret;
    }
private:
	stack<int> sta1;
	stack<int> sta2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */