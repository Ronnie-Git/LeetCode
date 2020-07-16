class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r) {
        	mid = (l + r) >> 1;
        	if (nums[mid] <= mid) l = mid + 1;
        	else r = mid - 1;
        }
        return l;
    }
};