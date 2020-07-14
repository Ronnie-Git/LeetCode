int searchInsert(int* nums, int numsSize, int target) {
    int l = -1, r = numsSize - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (nums[mid] < target) l = mid;
        else r = mid - 1;
    }
    return l + 1;
}