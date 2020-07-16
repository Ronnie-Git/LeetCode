class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int flag = 0, sum = 0, res = 0, minn = -0x3f3f3f3f;
    	for (int i = 0; i < nums.size(); ++i) {
    		if (sum + nums[i] >= 0) {
    			sum += nums[i];
    			res = (sum > res ? sum : res);
    		} else {
    			sum = 0;
    		}
    		if (flag) continue;
    		if (nums[i] >= 0) flag = 1;
    		minn = (nums[i] > minn ? nums[i] : minn);
    	}
        return flag ? res : minn;
    }
};