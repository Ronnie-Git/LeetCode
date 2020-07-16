class Solution {
public:
	int _find(vector<int> &arr, int key) {
		int l = 0, r = arr.size(), mid;
		while (l < r) {
			mid = (l + r) >> 1;
			if (arr[mid] >= key) r = mid;
			else l = mid + 1;
		}
		return l;
	}
    int search(vector<int>& nums, int target) {
    	return _find(nums, target) - _find(nums, target); 
    }
};