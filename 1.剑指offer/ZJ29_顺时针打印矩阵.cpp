class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
    	if (!matrix.size()) return res;
    	int n = matrix.size(), m = matrix[0].size();
    	int starti = 0, endi = n - 1, startj = 0, endj = m - 1;
    	while (starti <= endi && startj <= endj) {
    		for (int j = startj; j <= endj; ++j) res.push_back(matrix[starti][j]);
    		for (int i = starti + 1; i <= endi; ++i) res.push_back(matrix[i][endj]);	
    		if (starti < endi && startj < endj) { 
    			for (int j = endj - 1; j > startj; --j) res.push_back(matrix[endi][j]);
    			for (int i = endi; i > starti; --i) res.push_back(matrix[i][startj]);
			}
			++starti, --endi, ++startj, --endj;
    	}
    	return res;
    }
};