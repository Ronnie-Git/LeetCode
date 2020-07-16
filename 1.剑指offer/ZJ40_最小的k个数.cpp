class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
    	vector<int> res;
        if (k < 1) return res;
    	priority_queue<int, vector<int>, less<int>> q;
    	for (int i = 0; i < k; ++i) q.push(arr[i]);
    	for (int i = k; i < arr.size(); ++i) {
    		if (arr[i] >= q.top()) continue;
    		q.pop();
    		q.push(arr[i]);
    	}
    	while (!q.empty()) {
    		res.push_back(q.top());
    		q.pop();
    	}
    	return res;
    }
};