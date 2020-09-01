/*************************************************************************
	> File Name: 15_三数之和.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Aug 2020 03:54:57 PM CST
 ************************************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 2 < nums.size(); ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            twoSum(nums, i + 1, nums[i], res);
        }
        return res;
    }

    void twoSum(vector<int> &nums, int ind, int x, vector<vector<int> > &res) {
        int i = ind, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] + x == 0) {
                vector<int> temp = {x, nums[i], nums[j]};
                res.push_back(temp);
                ++i, --j;
                while(i < j && nums[i] == nums[i - 1]) ++i;
                while(i < j && nums[j] == nums[j + 1]) --j;
            } else if (nums[i] + nums[j] + x > 0) {
                j -= 1;
            } else {
                i += 1;
            }
        }
        return ;
    }
};
