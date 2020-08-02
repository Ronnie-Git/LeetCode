/*************************************************************************
	> File Name: 08.03_魔术索引.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 31 Jul 2020 09:20:55 AM CST
 ************************************************************************/

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        return search(nums, 0, nums.size());
    }

    int search(vector<int> &nums, int l, int r) {
        if (l >= r) return -1;
        int mid = (l + r) >> 1;
        int res = search(nums, l, mid);
        if (res != -1) return res;
        if (nums[mid] == mid) return mid;
        return search(nums, mid + 1, r);
    }
};
