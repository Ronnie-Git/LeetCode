class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
    	if (nums.size() <= 1) return nums;
        int j = 0;
        while (j < nums.size() && nums[j] & 1) ++j; 
    	for (int i = j + 1; i < nums.size() && j < nums.size(); i++) {
    		if (j < i && nums[i] % 2 == 1) {
    			nums[i] ^= nums[j];
    			nums[j] ^= nums[i];
    			nums[i] ^= nums[j];
                while (j < nums.size() && nums[j] & 1) ++j;
    		}
    	}
    	return nums;
    }
};