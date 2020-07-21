class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            while (l < r && (nums[l] & 1)) l++;
            while (l < r && (nums[r] & 1) == 0) r--;
            if (l < r) {
                nums[l] ^= nums[r], nums[r] ^= nums[l], nums[l] ^= nums[r];
            }
        }
        return nums;
    }
};
