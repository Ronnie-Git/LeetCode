class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.count(target - nums[i])) {
                res.push_back(hash[target - nums[i]] - 1);
                res.push_back(i);
            }
            hash[nums[i]] = i + 1;
        }
        return res;
    }
};