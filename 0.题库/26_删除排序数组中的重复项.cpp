/*
 * 第一种做法
 * 计数排序
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int count = 0, len = nums.size();
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[i - 1]) ++count;
            else nums[i - count] = nums[i];
        }
        return len - count;
    }
};

/*
 * 第二种做法
 * 双指针
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0, len = nums.size() - 1;
        for (int j = 1; j <= len; j++) {
            if (nums[i] == nums[j]) continue;
            nums[++i] = nums[j];
        }
        return i + 1;
    }
};