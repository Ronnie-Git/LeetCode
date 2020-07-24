/*************************************************************************
	> File Name: 41_数据流中的中位数.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Jul 2020 10:43:56 AM CST
 ************************************************************************/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        while (!smalltop.empty()) smalltop.pop();
        while (!bigtop.empty()) bigtop.pop();
    }
    
    void addNum(int num) {
        if (bigtop.size() != smalltop.size()) {
            bigtop.emplace(num);
            smalltop.emplace(bigtop.top());
            bigtop.pop();
        } else {
            smalltop.emplace(num);
            bigtop.emplace(smalltop.top());
            smalltop.pop();
        }
        
        return ;
    }
    
    double findMedian() {
        return ((bigtop.size() + smalltop.size()) & 1 ? bigtop.top() : (bigtop.top() * 1.0 + smalltop.top() * 1.0) / 2.0);
    }
private:
    priority_queue<int, vector<int>, greater<int> > smalltop;
    priority_queue<int, vector<int>, less<int> > bigtop;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
