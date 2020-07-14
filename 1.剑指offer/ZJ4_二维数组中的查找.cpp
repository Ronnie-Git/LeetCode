class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    	if (matrix.size() == 0) return false;
    	int i = 0, j = matrix[0].size() - 1, iend = matrix.size() - 1, jend = 0;
    	while (i <= iend && j >= jend) {
    		if (matrix[i][j] == target) return true;
    		if (matrix[i][j] > target) j--;
    		else i++;
    	}
    	return false;
    }
};