class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if (nums.front() <= nums.back()) {
            return search(nums, target, l, r);
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
            r = nums.size() - 1;
        }
        return search(nums, target, l, r);
    }

private:
    int search(vector<int>& nums, int target, int l, int r) {
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
};
