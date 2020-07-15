class Solution {
public:
    vector<int> printNumbers(int n) {
    	vector<int> res;
    	int maxn = pow(10, n) - 1;
    	for (int i = 1; i <= maxn; ++i) {
    		res.push_back(i);
    	}
    	return res;
    }
};