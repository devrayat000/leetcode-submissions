class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        // Prefix sum
        for (int i = 1; i < n; i++) {
            nums[i] = nums[i] + nums[i - 1];
        }

        // Dynamic sliding window
        int l = -1, r = 0, steps = INT_MAX;
        while (l <= n && !((r == n - 1) && (nums[r] - (l > -1 ? nums[l] : 0)) < target)) {
            int tmp = nums[r] - (l > -1 ? nums[l] : 0);
            println("tmp={}", tmp);
            if (tmp < target) {
                r++;
            } else {
                steps = min(steps, r - l);
                l++;
            }
        }
        return steps == INT_MAX ? 0 : steps;
    }
};