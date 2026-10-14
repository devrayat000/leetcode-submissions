int binary_search(int* nums, int numsSize, int target, int l, int r) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (target < nums[m]) {
            r = m - 1;
        } else if (target > nums[m]) {
            l = m + 1;
        } else {
            return m;
        }
    }
    return -1;
}

int search(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize - 1;
    if (nums[l] <= nums[r]) {
        return binary_search(nums, numsSize, target, l, r);
    }
    while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] < nums[r]) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (target >= nums[0]) {
        l = 0;
        r--;
    } else {
        r = numsSize - 1;
    }
    return binary_search(nums, numsSize, target, l, r);
}