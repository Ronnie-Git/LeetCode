/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define swap(a, b) { \
    __typeof(a) _temp = a; a = b; b = _temp; \
}

void quick(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, k = num[(l + r) >> 1];
        do {
            while (num[x] < k) ++x;
            while (num[y] > k) --y;
            if (x <= y) {
                swap(num[x], num[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick(num, x, r);
        r = y;
    }
}

void func(int *num, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (num[i] == num[i + 1]) num[i] = -1;
    }
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    quick(nums1, 0, nums1Size - 1);
    quick(nums2, 0, nums2Size - 1);
    func(nums1, nums1Size);
    func(nums2, nums2Size);
    
    int m = nums1Size < nums2Size ? nums1Size : nums2Size;
    int *n = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] == -1) continue;
        for (int j = 0; j < nums2Size; j++) {
            if (nums2[j] == -1) continue;
            if (nums1[i] < nums2[j]) break;
            if (nums1[i] == nums2[j]) {
                n[(*returnSize)++] = nums1[i];
                break;
            }
        }
    }
    return n;
}