class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
    	vector<vector<int>> res;
    	int l = 1, r = 1, sum = 0;
    	while (l < target) {
    		if (sum + r <= target) {
    			sum = sum + r++;
                if (sum == target) {
                	vector<int> temp;
                	for (int i = l; i < r; ++i) temp.push_back(i);
                	res.push_back(temp);
            	}
    		} else {
    			sum -= l++;
    		}
    	}
    	return res;
    }
};