class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k < 2)
            return 0;

        int n = nums.size();
        int l = 0, count = 0, prod = 1;

        for (int r = 0; r < n; r++) {
            prod *= nums[r];
            while (prod >= k) {
                prod /= nums[l];
                l++;
            }
            count += r - l + 1;
        }
        return count;
    }
};