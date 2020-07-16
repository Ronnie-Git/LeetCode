class Solution {
public:
	bool check(vector<int> &num, int l, int r) {
		if (l >= r) return true;
		int key = num[r], i = l, j;
		while (i < r && num[i] < key) ++i;

		for (j = i; j < r; ++j) 
			if (num[j] < key) return false;
		return check(num, l, i - 1) && check(num, i, r - 1);
	}

    bool verifyPostorder(vector<int>& postorder) {
    	return check(postorder, 0, postorder.size() - 1);
    }
};