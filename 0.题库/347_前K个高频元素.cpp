/*************************************************************************
	> File Name: 347_前K个高频元素.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Sep 2020 08:25:21 PM CST
 ************************************************************************/


class Solution {
public:
    class cmp {
    public:
        bool operator () (const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp > q;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] ++;
        }

        for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            q.push(*it);
            if (q.size() > k) q.pop();
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().first);
            q.pop();
        }

        return res;
    }
    
};
