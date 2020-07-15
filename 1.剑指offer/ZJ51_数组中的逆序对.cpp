class Solution {
public:
	void merge(vector<int> &arr, vector<int> &temp, int l, int r, int &ans) {
		if (r - l < 2) return ;
		int mid = (l + r) / 2;
		merge(arr, temp, l, mid, ans);
		merge(arr, temp, mid, r, ans);
		int i = l, j = mid, k = 0;
		while (i < mid || j < r) {
			if (j >= r || (i < mid && arr[i] <= arr[j])) {
				temp[k++] = arr[i++];
			} else {
				temp[k++] = arr[j++];
				ans += (mid - i);
			}
		}
		for (int p = 0; p < k; p++) arr[p + l] = temp[p];
		return ;
	}

    int reversePairs(vector<int>& nums) {
    	vector<int> temp(nums.size());
    	int ans = 0;
    	merge(nums, temp, 0, nums.size(), ans);
    	return ans;
    }
};