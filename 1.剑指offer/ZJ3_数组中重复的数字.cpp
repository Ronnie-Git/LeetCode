class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int, int> m;
        for (int i  = 0; i < nums.size(); ++i) {
        	if (m.count(nums[i])) return nums[i];
        	m[nums[i]] = 1;
        }
        return 0;
    }
};