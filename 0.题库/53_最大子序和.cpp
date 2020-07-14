int maxSubArray(int* nums, int numsSize) {
    int ans = 0, flag = 0, temp = 0, m;
    for (int i = 0; i < numsSize; i++) {
        temp += nums[i];
        if (temp <= 0) temp = 0;
        if (temp > ans) ans = temp;

        if (flag) continue;
        if (nums[i] > 0) flag = 1;
        if (i == 0 || nums[i] > m) m = nums[i];
    }
    return (flag ? ans : m);
}