#define swap(a, b) { \
    __typeof(a) _temp = a; a = b; b = _temp; \
}

bool containsDuplicate(int* nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        int flag = 0;
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] == nums[j + 1]) return true;
            if (nums[j] < nums[j + 1]) continue;
            swap(nums[j], nums[j + 1]);
            flag = 1;
        }
        if (!flag) break;
    }
    return false;
}