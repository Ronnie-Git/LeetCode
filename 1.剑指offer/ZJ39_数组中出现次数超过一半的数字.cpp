class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	int x = 0, cnt = 0;
    	for (int i = 0; i < nums.size(); i++) {
    		if (cnt == 0) x = nums[i];
    		cnt += (x == nums[i] ? 1 : -1);
    	}
    	return x;
    }
};