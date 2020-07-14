#define swap(a, b) { \
    __typeof(a) _temp = a; a = b; b = _temp; \
}

void merge(int* nums1, int m, int* nums2, int n) {
    for (int i = m; i < m + n; i++) nums1[i] = nums2[i - m];
    for (int i = m - 1; i < m + n - 1; i++) {
        for (int j = i; j >= 0; j--) {
            if (nums1[j] > nums1[j + 1]) swap(nums1[j], nums1[j + 1]);
        }
    }
    return ;
}