class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> res;
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			if (nums[l] + nums[r] == target) {
				res.push_back(nums[l]);
				res.push_back(nums[r]);
				break;
			}
			if (nums[l] + nums[r] > target) --r;
			else ++l;
		}
		return res;
    }
};