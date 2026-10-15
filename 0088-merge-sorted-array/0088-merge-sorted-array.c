void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int r1 = m - 1, r2 = n - 1, p = m + n - 1;
    while (r2 > -1) {
        if (r1 > -1 && nums1[r1] > nums2[r2]) {
            nums1[p] = nums1[r1];
            r1--;
        } else {
            nums1[p] = nums2[r2];
            r2--;
        }
        p--;
    }
}